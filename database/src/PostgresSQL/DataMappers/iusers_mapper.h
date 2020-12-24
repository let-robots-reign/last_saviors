#ifndef DATABASE_IUSERSMAPPER_H
#define DATABASE_IUSERSMAPPER_H


#include <idb_conn.h>
#include "user.h"


class IUsersMapper {
public:
    IUsersMapper() = default;
    virtual ~IUsersMapper() = default;;

    virtual bool sign_in(User user) = 0;

    virtual bool sign_up(User user) = 0;

protected:
    std::shared_ptr<IDBConn> dbConn = nullptr;
};


#endif //DATABASE_IUSERSMAPPER_H
