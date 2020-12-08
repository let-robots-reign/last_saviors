#include "method_event_handler.h"

template<typename TObject, typename... TParams>
MethodEventHandler<TObject, TParams...>::MethodEventHandler(const TObject &object, MethodEventHandler::TMethod method)
        : AbstractEventHandler<TParams...>(), object(object), method(method) {}

template<typename TObject, typename... TParams>
void MethodEventHandler<TObject, TParams...>::call(TParams... params) {
    (object.*method)(params...);
}

template<typename TObject, typename... TParams>
bool MethodEventHandler<TObject, TParams...>::equals(const AbstractEventHandler<TParams...> &rhs) const {
    const MethodHandlerType _rhs = dynamic_cast<const MethodHandlerType *>(&rhs);
    return (_rhs != nullptr && &object == &_rhs.object && method == _rhs.method);
}
