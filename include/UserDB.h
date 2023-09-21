#include "FileReader.h"
#include "FileReader.h"
#include "User.h"
#include <set>
#pragma once

class UserDB {
private:

    UserDB* instance;
    std::set<std::string,std::string> DB;

    UserDB(){};
public:
    static UserDB* getInstance();
    // Retorna true si se cargo la base de datos
    bool loadUsers(std::string path);
    // Retorna nullptr si el usuario no existe.
    User* login(std::string user, std::string psw);

};