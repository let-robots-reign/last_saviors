#ifndef DATABASE_IUSERSMAPPER_H
#define DATABASE_IUSERSMAPPER_H

#include "user.h"

class IUsersMapper {
public:
    virtual bool sign_in(User user) = 0;

    virtual bool sign_up(User user) = 0;
};


#endif //DATABASE_IUSERSMAPPER_H
