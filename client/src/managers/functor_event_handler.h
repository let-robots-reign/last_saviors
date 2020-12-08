#ifndef LAST_SAVIORS_FUNCTOR_EVENT_HANDLER_H
#define LAST_SAVIORS_FUNCTOR_EVENT_HANDLER_H

#include "event_handler.h"

template<typename TFunctor, typename ...TParams>
class FunctorEventHandler : public AbstractEventHandler<TParams...> {
public:
    explicit FunctorEventHandler(TFunctor &functor);

    void call(TParams... params) final;

private:
    TFunctor &functor;
};

template<typename TFunctor, typename ...TParams>
AbstractEventHandler<TParams...> &createFunctorEventHandler(TFunctor &&functor) {
    return *new FunctorEventHandler<TFunctor, TParams...>(functor);
}

#define FUNCTOR_HANDLER(Functor) createFunctorEventHandler(Functor)

#endif //LAST_SAVIORS_FUNCTOR_EVENT_HANDLER_H
