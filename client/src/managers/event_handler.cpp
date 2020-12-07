#include "event_handler.h"

template<typename... TParams>
bool AbstractEventHandler<TParams...>::operator==(const AbstractEventHandler::handlerType &rhs) const {
    return equals(rhs);
}

template<typename... TParams>
bool AbstractEventHandler<TParams...>::operator!=(const AbstractEventHandler::handlerType &rhs) const {
    return !(*this == rhs);
}
