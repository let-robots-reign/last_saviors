#include "method_event_handler.h"

template<typename TMethodHolder, typename... TParams>
MethodEventHandler<TMethodHolder, TParams...>::MethodEventHandler(TMethodHolder &holder)
        : methodHolder(holder) {}

template<typename TMethodHolder, typename... TParams>
void MethodEventHandler<TMethodHolder, TParams...>::call(TParams... params) {
    (methodHolder->object.*methodHolder->method)(params...);
}

template<typename TMethodHolder, typename... TParams>
bool MethodEventHandler<TMethodHolder, TParams...>::equals(const AbstractEventHandler<TParams...> &rhs) const {
    const auto *_rhs = dynamic_cast<const MethodHandlerType *>(&rhs);
    return (_rhs != nullptr && *methodHolder == *_rhs->methodHolder);
}

template<typename TObject, typename TResult, typename... TParams>
MethodHolder<TObject, TResult, TParams...>::MethodHolder(TObject &object, MethodHolder::TMethod method)
        : object(object), method(method) {}

template<typename TObject, typename TResult, typename... TParams>
bool MethodHolder<TObject, TResult, TParams...>::operator==(const MethodHolder::MethodHolderType &rhs) const {
    return (&object == &rhs.object && method == rhs.method);
}

template<typename TObject, typename TResult, typename... TParams>
bool MethodHolder<TObject, TResult, TParams...>::operator!=(const MethodHolder::MethodHolderType &rhs) const {
    return !(*this == rhs);
}
