#include "functor_event_handler.h"

template<typename TFunctor, typename... TParams>
FunctorEventHandler<TFunctor, TParams...>::FunctorEventHandler(FunctorHolder<TFunctor> &holder)
        : AbstractEventHandler<TParams...>(), functorHolder(holder) {}

template<typename TFunctor, typename... TParams>
void FunctorEventHandler<TFunctor, TParams...>::call(TParams... params) {
    functorHolder.functor(params...);
}

template<typename TFunctor, typename... TParams>
bool FunctorEventHandler<TFunctor, TParams...>::equals(const AbstractEventHandler<TParams...> &rhs) const {
    const auto *_rhs = dynamic_cast<const FunctorHandlerType *>(&rhs);
    return (_rhs != nullptr && *functorHolder == *_rhs->functorHolder);
}

template<typename TFunctor>
FunctorHolder<TFunctor>::FunctorHolder(TFunctor &functor) : functor(functor) {}

template<typename TFunctor>
bool FunctorHolder<TFunctor>::operator==(const FunctorHolder<TFunctor> &rhs) const {
    return (functor == rhs.functor);
}

template<typename TFunctor>
bool FunctorHolder<TFunctor>::operator!=(const FunctorHolder<TFunctor> &rhs) const {
    return !(*this == rhs);
}
