#include "functor_event_handler.h"

template<typename TFunctor, typename... TParams>
FunctorEventHandler<TFunctor, TParams...>::FunctorEventHandler(FunctorHolder<TFunctor> &holder)
        : AbstractEventHandler<TParams...>(), functorHolder(holder) {}

template<typename TFunctor, typename... TParams>
void FunctorEventHandler<TFunctor, TParams...>::call(TParams... params) {
    functorHolder.functor(params...);
}

template<typename TFunctor>
FunctorHolder<TFunctor>::FunctorHolder(TFunctor &functor) : functor(functor) {}
