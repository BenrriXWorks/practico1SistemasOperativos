#include "../../include/ArgumentsLoader.h"
using namespace std;

std::string 
    ArgumentsLoader::i="",
    ArgumentsLoader::o="",
    ArgumentsLoader::v="",
    ArgumentsLoader::u="",
    ArgumentsLoader::f="",
    ArgumentsLoader::t="";
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
    char* i_aux=nullptr, *o_aux=nullptr, *v_aux=nullptr, *u_aux=nullptr, *f_aux=nullptr, *t_aux=nullptr;
    while ((opt = getopt(argc, argv, "i:o:v:u:f:t:")) != -1) {
        switch (opt) {
            case 'i':
                i_aux = optarg;
                break;
            case 'o':
                o_aux = optarg;
                break;
            case 'v':
                v_aux = optarg;
                break;
            case 'u':
                u_aux = optarg;
                break;
            case 'f':
                f_aux = optarg;
                break;
            case 't':
                t_aux = optarg;
                break;
            default:
                printf("ArgumentsLoader: Argumento invalido o vacio \"-%c\".\n", optopt);
                return false;
        }
    }
    bool correct=true;
    if (u_aux == nullptr || (u = strip(string(u_aux))).empty())
        printf("ArgumentsLoader: Debe ingresar un usuario con -u {user}\n"),correct=false;
    if (i_aux != nullptr && (i = strip(string(i_aux))).empty())
        printf("ArgumentsLoader: El argumento -i esta vacio\n"),correct=false;
    if (o_aux != nullptr && (o = strip(string(o_aux))).empty())
        printf("ArgumentsLoader: El argumento -o esta vacio\n"),correct=false;
    if (v_aux != nullptr && (v = stripAllOf(string(v_aux)," ;")).empty())
        printf("ArgumentsLoader: El argumento -v esta vacio\n"),correct=false;
    if (f_aux != nullptr && (f = strip(string(f_aux))).empty())
        printf("ArgumentsLoader: El argumento -f esta vacio\n"),correct=false;
    if (t_aux != nullptr && (t = strip(string(t_aux))).empty())
        printf("ArgumentsLoader: El argumento -t esta vacio\n"),correct=false;
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