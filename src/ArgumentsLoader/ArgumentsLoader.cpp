#include "../../include/ArgumentsLoader.h"
using namespace std;

std::string 
    ArgumentsLoader::p="",
    ArgumentsLoader::v="",
    ArgumentsLoader::u="";
ArgumentsLoader* ArgumentsLoader::instance = nullptr;
bool ArgumentsLoader::loaded = false;

ArgumentsLoader* ArgumentsLoader::getInstance(){
    if (instance == nullptr)
        instance = new ArgumentsLoader();
    return instance;
}

bool ArgumentsLoader::init(int argc,char** argv){
    if (loaded == true)
        return (printf("ArgumentsLoader: Esta clase ya se ha inicializado\n"),true);

    int opt;
    char* p_aux=nullptr, *v_aux=nullptr, *u_aux=nullptr;
    while ((opt = getopt(argc, argv, "u:p:v:")) != -1) {
        switch (opt) {
            case 'p':
                p_aux = optarg;
                break;
            case 'v':
                v_aux = optarg;
                break;
            case 'u':
                u_aux = optarg;
                break;
            default:
                printf("ArgumentsLoader: Argumento invalido o vacio \"-%c\".\n", optopt);
                return false;
        }
    }

    bool correct=true;
    if (u_aux == nullptr || (u = strip(string(u_aux))).empty())
        printf("ArgumentsLoader: Debe ingresar un usuario con -u {user}\n"),correct=false;
    if (v_aux != nullptr && (v = stripAllOf(string(v_aux)," ;")).empty())
        printf("ArgumentsLoader: El argumento -v esta vacio\n"),correct=false;
    if (p_aux == nullptr || (p = strip(string(p_aux))).empty())
        printf("ArgumentsLoader: Debes ingresar una contrasena\n"),correct=false;
    if (!correct)
        return false;
    
    if (v_aux != nullptr && string(v_aux).find_first_not_of("0123456789; ") != string::npos)
        return (printf("ArgumentsLoader: El formato del vector debe ser N1;N2;...;Nn y solo contener caracteres numericos\nVector ingresado: {%s}\n"
        , v_aux),false);
    return true;
};