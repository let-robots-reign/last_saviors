#ifndef DATABASE_USERSMAPPER_H
#define DATABASE_USERSMAPPER_H


#include <memory>
#include "iusers_mapper.h"
#include "idb_conn.h"


class UsersMapper : public IUsersMapper {
public:
    explicit UsersMapper(std::shared_ptr<IDBConn> &new_dbConn);

    bool sign_in(User user) override;

    bool sign_up(User user) override;
};


#endif //DATABASE_USERSMAPPER_H
