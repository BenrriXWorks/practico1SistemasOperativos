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

    for (std::string line : fr.readLines()){
        std::vector<std::string> tokens = split(line,';');
        if (tokens.size() != 2)
            return (printf("UserDB: Formato incorrecto de la base de datos de usuarios en la linea {%s}\n",line.c_str()));
        if (tokens.at(0).empty() || tokens.at(1).empty())
            return (printf("UserDB: Error, falta usuario o contrasena en la linea {%s}",line.c_str()),false);
        if (!DB.emplace(std::make_pair(tokens.at(0),tokens.at(1))).second)
            return (printf("UserDB: El usuario de la linea {%s} ya existe o no ha podido ser agregado por un motivo desconocido\n",line.c_str()));
    }
    return true;
}