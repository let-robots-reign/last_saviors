#ifndef DATABASE_USER_H
#define DATABASE_USER_H


#include <string>

class User {
public:
    int id;
    std::string login;
    std::string password;
    std::string name;
    int age;
};


#endif //DATABASE_USER_H
