#include <cstdlib>
#include <cstdio>
#include "include/Menu.h"
#include "include/UserDB.h"
#include "include/ArgumentsLoader.h"
#include "include/EnvLoader.h"

int main(int argc, char** argv){

    EnvLoader* envLoader = EnvLoader::getInstance();
    Menu* menu = Menu::getInstance();
    UserDB* userDB = UserDB::getInstance();
    ArgumentsLoader* argumentsLoader = ArgumentsLoader::getInstance();

    if (!argumentsLoader->init(argc,argv))
        return(printf("Main: No se inicializaron los argumentos correctamente\n"),EXIT_FAILURE);
    if (!envLoader->init())
        return (printf("Main: No se cargaron las variables de entorno correctamente\n"),EXIT_FAILURE);
    if (!userDB->loadUsers(envLoader->getUserDB_path()))
        return (printf("Main: No se cargaron los usuarios correctamente\n"),EXIT_FAILURE);
    if (!userDB->fetchUser(argumentsLoader->get_u()))
        return (printf("Main: El usuario {%s} no existe\n",argumentsLoader->get_u().c_str()),EXIT_FAILURE);

    User* user = userDB->login(argumentsLoader->get_u(), argumentsLoader->get_p());
    if (user == nullptr)
        return (printf("Main: Constrasena invalida\n"),EXIT_FAILURE);
    
    menu->init(user);
    menu->display();

    printf("Funciono !\n");
    return EXIT_SUCCESS;
}