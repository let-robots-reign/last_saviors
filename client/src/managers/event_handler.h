#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

template<typename ...TParams>
class AbstractEventHandler {
public:
    virtual void call(TParams... params) = 0;

protected:
    AbstractEventHandler() = default;
};

#endif //CLIENT_MANAGER_H
