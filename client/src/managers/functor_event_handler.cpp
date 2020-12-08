#include "functor_event_handler.h"

template<typename TFunctor, typename... TParams>
FunctorEventHandler<TFunctor, TParams...>::FunctorEventHandler(TFunctor &functor)
        : AbstractEventHandler<TParams...>(), functor(functor) {}

template<typename TFunctor, typename... TParams>
void FunctorEventHandler<TFunctor, TParams...>::call(TParams... params) {
    functor(params...);
}
