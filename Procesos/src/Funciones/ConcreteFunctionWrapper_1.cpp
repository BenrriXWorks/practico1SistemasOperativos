#include "../../include/ConcreteFunctionWrapper_1.h"

bool ConcreteFunctionWrapper_1 :: execute() {

    EnvLoader* env = EnvLoader::getInstance();
    UserDB* db = UserDB::getInstance();

    FileWriter fw;
    if (!fw.openAppend(env->getUserDB_path()))
        return (printf("Function 1: No se pudo abrir el archivo de usuarios en {%s}",env->getUserDB_path().c_str()),false);
    
    std::string username, password;
    printf("Ingrese el usuario a agregar: ");
    getline(std::cin, username);
    if ((username = stripAllOf(username," \n\t'\"\\")).empty())
        return (printf("Function 1: Por favor ingrese un usuario\n"),false);
    if (username.find(';') != std::string::npos)
        return (printf("Function 1: El nombre de usuario contiene caracteres invalidos (\n\t'\"\\)\n"),false);
    printf("Ingrese una contrasena: ");
    getline(std::cin, password);
    if (password.empty())
        return (printf("Function 1: Error, la contrasena no puede ser vacia\n"),false);
    if (password.find(';') != std::string::npos)
        return (printf("Function 1: La contrasena contiene caracteres invalidos (\n\t'\")\n\\"),false);
    if (db->fetchUser(username))
        return (printf("Function 1: El usuario {%s} ya existe!\n",username.c_str()),false);
    
    
    printf("Creando usuario = (u:{%s}, p:{%s})\n",username.c_str(),password.c_str());

    if (!db->addUserCache(username,password))
        return (printf("Function 1: Hubo un error al agregar el usuario a la base de datos\n"),false);
    
    fw << username << ";" << password << "\n";

    fw.close();
    return true;
}