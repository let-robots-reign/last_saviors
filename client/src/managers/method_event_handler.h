#ifndef LAST_SAVIORS_METHOD_EVENT_HANDLER_H
#define LAST_SAVIORS_METHOD_EVENT_HANDLER_H

#include "event_handler.h"

// обработчик события - метод класса
template<typename TObject, typename ...TParams>
class MethodEventHandler : public AbstractEventHandler<TParams...> {
    using TMethod = void (TObject::*)(TParams...);
    using MethodHandlerType = MethodEventHandler<TObject, TParams...>;
public:
    MethodEventHandler(const TObject &object, TMethod method);

    void call(TParams... params) final;

protected:
    bool equals(const AbstractEventHandler<TParams...> &rhs) const override {
        const MethodHandlerType _rhs = dynamic_cast<const MethodHandlerType *>(&rhs);
        return (_rhs != nullptr && &object == &_rhs.object && method == _rhs.method);
    }

private:
    TObject *object;
    TMethod method;
};

template<typename TObject, typename ...TParams>
AbstractEventHandler<TParams...> &createMethodEventHandler(TObject &object, void (TObject::*method)(TParams...)) {
    return *new MethodEventHandler<TObject, TParams...>(object, method);
}

#define METHOD_HANDLER(Object, Method) createMethodEventHandler(Object, &Method)
#define SELF_METHOD_HANDLER(Method) METHOD_HANDLER(*this, Method)

#endif //LAST_SAVIORS_METHOD_EVENT_HANDLER_H
