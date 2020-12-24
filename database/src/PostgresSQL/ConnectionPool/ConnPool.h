#ifndef DB_CONNPOOL_H
#define DB_CONNPOOL_H


#include "pgconnection.h"

class ConnPool {
public:
    ConnPool() = default;
    virtual std::shared_ptr<PGConnection> connection() = 0;
    virtual void freeConnection(std::shared_ptr<PGConnection>) = 0;

private:
    virtual void createPool() = 0;
};


#endif //DB_CONNPOOL_H
