#ifndef DATABASE_USER_H
#define DATABASE_USER_H


#include <string>


class User {
public:
    User() {};
    User(std::string &_login, std::string &_password, std::string &_name, std::string &_age)
        : login(_login), password(_password), name(_name), age(_age) {}

    int id{};
    std::string login;
    std::string password;
    std::string name;
    std::string age;
};


#endif //DATABASE_USER_H
