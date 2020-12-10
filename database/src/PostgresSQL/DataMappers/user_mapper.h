#ifndef DATABASE_USERSMAPPER_H
#define DATABASE_USERSMAPPER_H

#include <memory>
#include <pg_conn_pool.h>
#include "iusers_mapper.h"
#include "idb_conn.h"

class UsersMapper : public IUsersMapper {
public:
    UsersMapper(std::shared_ptr<PGConnPool> );

    bool sign_in(User user) override;

    bool sign_up(User user) override;

private:
    std::shared_ptr<PGConnPool> dbConn = nullptr;

};


#endif //DATABASE_USERSMAPPER_H
