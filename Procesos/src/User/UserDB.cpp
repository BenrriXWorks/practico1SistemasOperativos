#include "../../include/UserDB.h"

UserDB* UserDB::instance = nullptr;
std::map<std::string,std::string> UserDB::DB = std::map<std::string,std::string>();

UserDB* UserDB::getInstance(){
    if (instance == nullptr)
        instance = new UserDB();
    return instance;
}

bool UserDB::loadUsers(std::string path){
    FileReader fr;
    if (!fr.open(path))
        return (printf("UserDB: No se pudo abrir el archivo en {%s}\n", path.c_str()),false);

    DB.emplace("admin","admin");

    for (std::string line : fr.readLines()){
        if (line.empty()) continue;
        std::vector<std::string> tokens = split(stripAllOf(line,"\n\r\t"),';');
        if (tokens.size() != 2)
            return (printf("UserDB: Formato incorrecto de la base de datos de usuarios en la linea {%s}\n",line.c_str()));
        if (tokens.at(0).empty() || tokens.at(1).empty())
            return (printf("UserDB: Error, falta usuario o contrasena en la linea {%s}",line.c_str()),false);
        if (!DB.emplace(std::make_pair(tokens.at(0),tokens.at(1))).second)
            return (printf("UserDB: El usuario de la linea {%s} ya existe o no ha podido ser agregado por un motivo desconocido\n",line.c_str()));
    }
    fr.close();
    return true;
}

User* UserDB::login (std::string username, std::string password) const {
    std::map<std::string, std::string> :: iterator it;
    if ((it = DB.find(username)) != DB.end() && it->second == password){
        return new User(username, (username == "admin"));
    }
    return nullptr;
}

bool UserDB::addUserCache(std::string username, std::string password){

    if (fetchUser(username))
        return (printf("UserDB: El usuario ya existe en la cache.\n"),false);
    if (!DB.emplace(username,password).second){
        return (printf("UserDB: No se pudo agregar el usuario a la cache.\n"),false);
    }
    return true;
}