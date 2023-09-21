#include "../../include/ArgumentsLoader.h"
using namespace std;

std::string 
    ArgumentsLoader::p="",
    ArgumentsLoader::v="",
    ArgumentsLoader::u="";
std::vector<int> ArgumentsLoader::v_vector = vector<int>();
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
    if (p_aux != nullptr && (p = strip(string(p_aux))).empty())
        printf("ArgumentsLoader: El argumento -p esta vacio\n"),correct=false;
    if (!correct)
        return false;
    
    if (v_aux != nullptr){
        auto splitint = splitInt(v,';');
        if (!splitint.second)
            return (printf("ArgumentsLoader: El formato de entrada del vector -v {%s} es incorrecto\n",v_aux),false);
        v_vector = splitint.first;
    }

    return true;
};