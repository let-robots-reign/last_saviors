#ifndef LAST_SAVIORS_FUNCTOR_EVENT_HANDLER_H
#define LAST_SAVIORS_FUNCTOR_EVENT_HANDLER_H

#include "event_handler.h"

/*
 * код вида playButton.onButtonClick += FUNCTOR_HANDLER(clickHandler);
 * упадет, так как нельзя вывести типы только из функтора
 * Чтобы это решить, заведем обертку FunctorHolder
 */

template<typename TFunctor>
class FunctorHolder;

template<typename TFunctor, typename ...TParams>
class FunctorEventHandler : public AbstractEventHandler<TParams...> {
    using FunctorHandlerType = FunctorEventHandler<TFunctor, TParams...>;
public:
    explicit FunctorEventHandler(FunctorHolder<TFunctor> &holder);

    void call(TParams... params) final;

protected:
    bool equals(const AbstractEventHandler<TParams...> &rhs) const override;

private:
    FunctorHolder<TFunctor> &functorHolder;
};

template<typename TFunctor>
class FunctorHolder {
public:
    explicit FunctorHolder(TFunctor &functor);

    template<typename ...CallParams>
    inline explicit operator AbstractEventHandler<CallParams...> &() {
        return *new FunctorEventHandler<TFunctor, CallParams...>(*this);
    }

    bool operator==(const FunctorHolder<TFunctor> &rhs) const;

    bool operator!=(const FunctorHolder<TFunctor> &rhs) const;

private:
    TFunctor &functor;

    // чтобы был возможен call() в FunctorEventHandler
    template<typename Functor, typename ...TParams> friend class FunctorEventHandler;
};

template<typename TFunctor>
FunctorHolder<TFunctor> &createFunctorEventHandler(TFunctor &&functor) {
    return *new FunctorHolder<TFunctor>(functor);
}

#define FUNCTOR_HANDLER(Functor) createFunctorEventHandler(Functor)
#define LAMBDA_HANDLER(Lambda) FUNCTOR_HANDLER(Lambda)
#define STD_FUNCTION_HANDLER(StdFunction) FUNCTOR_HANDLER(StdFunction)
#define FUNCTION_HANDLER(Function) FUNCTOR_HANDLER(&Function)

#endif //LAST_SAVIORS_FUNCTOR_EVENT_HANDLER_H
