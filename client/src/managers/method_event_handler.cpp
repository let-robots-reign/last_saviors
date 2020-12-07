#include "method_event_handler.h"

template<typename TObject, typename... TParams>
MethodEventHandler<TObject, TParams...>::MethodEventHandler(const TObject &object, MethodEventHandler::TMethod method)
        : AbstractEventHandler<TParams...>(), object(object), method(method) {}

template<typename TObject, typename... TParams>
void MethodEventHandler<TObject, TParams...>::call(TParams... params) {
    (object.*method)(params...);
}
