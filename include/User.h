#include <string>
#pragma once

class User{
private:
    std::string username;
    bool admin;
public:
    inline std::string getUsername() {return username;};
    inline bool isAdmin(){return admin;};
};