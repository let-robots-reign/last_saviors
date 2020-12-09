#ifndef CLIENT_EVENT_HANDLER_H
#define CLIENT_EVENT_HANDLER_H

template<typename ...TParams>
class AbstractEventHandler {
public:
    virtual void call(TParams... params) = 0;

    // чтобы реализовать отписку (operator -=) от события, добавим операторы сравнения
    using HandlerType = AbstractEventHandler<TParams...>;

    bool operator==(const HandlerType &rhs) const;

    bool operator!=(const HandlerType &rhs) const;

protected:
    AbstractEventHandler() = default;

    virtual bool equals(const HandlerType &rhs) const = 0;
};

#endif //CLIENT_EVENT_HANDLER_H
