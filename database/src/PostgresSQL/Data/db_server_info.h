#ifndef DATABASE_DBSERVERINFO_H
#define DATABASE_DBSERVERINFO_H

#include <string>

class DBServerInfo {
public:
    DBServerInfo() = default;

private:
    std::string ip;
    std::string port;
    std::string login;
    std::string password;
};


#endif //DATABASE_DBSERVERINFO_H
