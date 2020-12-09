#ifndef LAST_SAVIORS_METHOD_EVENT_HANDLER_H
#define LAST_SAVIORS_METHOD_EVENT_HANDLER_H

#include "event_handler.h"

template<typename TObject, typename TResult, typename ...TParams>
class MethodHolder;

// обработчик события - метод класса
template<typename TMethodHolder, typename ...TParams>
class MethodEventHandler : public AbstractEventHandler<TParams...> {
    using MethodHandlerType = MethodEventHandler<TMethodHolder, TParams...>;
public:
    explicit MethodEventHandler(TMethodHolder &holder);

    void call(TParams... params) final;

protected:
    bool equals(const AbstractEventHandler<TParams...> &rhs) const override;

private:
    TMethodHolder &methodHolder;
};

template<typename TObject, typename TResult, typename ...TParams>
class MethodHolder {
    using MethodHolderType = MethodHolder<TObject, TResult, TParams...>;
    using TMethod = TResult(TObject::*)(TParams...);
public:
    MethodHolder(TObject &object, TMethod method);

    template<typename ...CallParams>
    inline explicit operator AbstractEventHandler<CallParams...> &() {
        return *new MethodEventHandler<MethodHolderType, CallParams...>(*this);
    }

    bool operator==(const MethodHolderType &rhs) const;

    bool operator!=(const MethodHolderType &rhs) const;

private:
    TObject &object;
    TMethod method;

template<typename TMethodHolder, typename ...Params> friend class MethodEventHandler;
};

template<typename TObject, typename ...TParams>
AbstractEventHandler<TParams...> &createMethodEventHandler(TObject &object, void (TObject::*method)(TParams...)) {
    return *new MethodEventHandler<TObject, TParams...>(object, method);
}

#define METHOD_HANDLER(Object, Method) createMethodEventHandler(Object, &Method)
#define SELF_METHOD_HANDLER(Method) METHOD_HANDLER(*this, Method)

#endif //LAST_SAVIORS_METHOD_EVENT_HANDLER_H
