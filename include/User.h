#include <string>
#pragma once

class User{
private:
    std::string username;
    bool admin;
public:
    inline std::string getUsername() const {return username;};
    inline bool isAdmin() const {return admin;};
    User(std::string username, bool admin) : username(username),admin(admin) {};
};