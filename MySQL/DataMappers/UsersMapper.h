#ifndef DATABASE_USERSMAPPER_H
#define DATABASE_USERSMAPPER_H


#include <memory>
#include "IUsersMapper.h"
#include "../Builder/IDBConn.h"

class UsersMapper : public IUsersMapper {
public:
    bool sign_in(User user) override;
    bool sign_up(User user) override;

private:
    std::shared_ptr<IDBConn> dbConn = nullptr;

};


#endif //DATABASE_USERSMAPPER_H
