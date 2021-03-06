#ifndef LAST_SAVIORS_METHOD_EVENT_HANDLER_H
#define LAST_SAVIORS_METHOD_EVENT_HANDLER_H

#include "event_handler.h"
#include "equality_checker.h"

template<typename TObject, typename ...TParams>
class MethodHolder;

// обработчик события - метод класса
template<typename TMethodHolder, typename ...TParams>
class MethodEventHandler : public AbstractEventHandler<TParams...> {
    using MethodHandlerType = MethodEventHandler<TMethodHolder, TParams...>;
public:
    explicit MethodEventHandler(TMethodHolder &holder) : methodHolder(holder) {}

    void call(TParams... params) final {
        (methodHolder.object.*methodHolder.method)(params...);
    }

protected:
    bool equals(const AbstractEventHandler<TParams...> &rhs) const override {
        const auto *_rhs = dynamic_cast<const MethodHandlerType *>(&rhs);
        return (_rhs != nullptr && methodHolder == _rhs->methodHolder);
    }

private:
    TMethodHolder &methodHolder;
};

template<typename TObject, typename ...TParams>
class MethodHolder {
    using MethodHolderType = MethodHolder<TObject, TParams...>;
    using TMethod = void(TObject::*)(TParams...);
public:
    MethodHolder(TObject &object, TMethod method) : object(object), method(method) {}

    template<typename ...CallParams>
    inline explicit operator AbstractEventHandler<CallParams...> &() {
        return *new MethodEventHandler<MethodHolderType, CallParams...>(*this);
    }

    inline bool operator==(const MethodHolderType &rhs) const {
        //return (&object == &rhs.object && method == rhs.method);
        return EqualityChecker<TObject>::equals(object, rhs.object) && EqualityChecker<TMethod>::equals(method, rhs.method);
    }

    inline bool operator!=(const MethodHolderType &rhs) const {
        return !(*this == rhs);
    }

private:
    TObject &object;
    TMethod method;

    // чтобы был возможен call() в MethodEventHandler
    template<typename TMethodHolder, typename ...Params> friend
    class MethodEventHandler;
};

template<typename TObject, typename ...TParams>
MethodHolder<TObject, TParams...> &createMethodEventHandler(TObject &object, void(TObject::*method)(TParams...)) {
    return *new MethodHolder<TObject, TParams...>(object, method);
}

#define METHOD_HANDLER(Object, Method) createMethodEventHandler(Object, &Method)
#define SELF_METHOD_HANDLER(Method) METHOD_HANDLER(*this, Method)

#endif //LAST_SAVIORS_METHOD_EVENT_HANDLER_H
