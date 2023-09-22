#include "FileReader.h"
#include "FileReader.h"
#include "User.h"
#include "Functions.h"
#include <map>
#pragma once

class UserDB {
private:

    static UserDB* instance;
    static std::map<std::string,std::string> DB;

    UserDB(){};
public:
    static UserDB* getInstance();
    // Retorna true si se cargo la base de datos
    bool loadUsers(std::string path);
    // Retorna nullptr si el usuario no existe.
    User* login(std::string user, std::string psw) const;
    // Retorna true si el usuario existe
    inline bool fetchUser(std::string user) const {return DB.find(user) != DB.end();};

};