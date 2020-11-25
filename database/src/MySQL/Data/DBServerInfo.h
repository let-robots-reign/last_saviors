#ifndef DATABASE_DBSERVERINFO_H
#define DATABASE_DBSERVERINFO_H

#include <string>

class DBServerInfo {
public:
//    DBServerInfo(std::string ip, std::string port, std::string login, std::string password);
    std::string ip;
    std::string port;
    std::string login;
    std::string password;
};

//DBServerInfo::DBServerInfo(std::string _ip, std::string _port, std::string _login, std::string _password) {
//
//}


#endif //DATABASE_DBSERVERINFO_H
