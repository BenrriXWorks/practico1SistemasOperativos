#include "../../include/ConcreteFunctionWrapper_1.h"

bool ConcreteFunctionWrapper_1 :: execute() {

    ArgumentsLoader* args = ArgumentsLoader::getInstance();

    FileWriter fw;
    if (!fw.openAppend(args->get_p()))
        return (printf("Function 1: No se pudo abrir el archivo de usuarios en {%s}",args->get_p()),false);
    
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
    
    UserDB* db = UserDB::getInstance();
    if (db->fetchUser(username)){
        return (printf("Function 1: El usuario {%s} ya existe!\n",username),false);
    }
    
    printf("Creando usuario = (u:{%s}, p:{%s})\n",username,password);

    fw << username << ";" << password;

    printf("Recuerda reiniciar el sistema para que el cambio surta efecto\n");
    return true;
}