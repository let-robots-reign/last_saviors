#ifndef PGBACKEND_H
#define PGBACKEND_H

#include <memory>
#include <mutex>
#include <string>
#include <queue>
#include <condition_variable>
#include <libpq-fe.h>
#include "pgconnection.h"
#include "ConnPool.h"


class PGConnPool : public ConnPool
{
public:
    PGConnPool();
    std::shared_ptr<PGConnection> connection() override;
    void freeConnection(std::shared_ptr<PGConnection>) override;

private:
    void createPool() override;
    
    std::mutex m_mutex;
    std::condition_variable m_condition;
    std::queue<std::shared_ptr<PGConnection>> m_pool;

    const int POOL = 10;


};

#endif //PGBACKEND_H
