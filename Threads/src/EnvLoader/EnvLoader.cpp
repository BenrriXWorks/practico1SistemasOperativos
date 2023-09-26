#include "../../include/EnvLoader.h"
using namespace std;

EnvLoader* EnvLoader::instance = nullptr;
bool EnvLoader::loaded = false;

bool EnvLoader::init(bool onlyFile){
    
    if (loaded==true)
        return (printf("EnvLoaded: Error, esta clase ya ha sido iniciada"),false);
    

    uint8_t conditionsMeet = 0;
    char* getenvChar;
    if (!onlyFile) {
        getenvChar  =  getenv("PATH_FILES_IN");
        if (getenvChar != nullptr) ++conditionsMeet, PATH_FILES_IN = string(getenvChar);
        getenvChar  =  getenv("PATH_FILES_OUT");
        if (getenvChar  != nullptr) ++conditionsMeet, PATH_FILES_OUT = string(getenvChar);
        getenvChar  =  getenv("AMOUNT_THREADS");
        if (getenvChar  != nullptr) ++conditionsMeet, N_THREADS = string(getenvChar);
        getenvChar  =  getenv("EXTENSION");
        if (getenvChar  != nullptr) ++conditionsMeet, EXTENSION = string(getenvChar);

        if (conditionsMeet == 4)
            return true;
    }

    FileReader fr;
    if (!fr.open(".env")){
        std::cerr << "EnvLoader: " <<
        "El archivo .env no ha podido ser abierto" << std::endl;
        return false;
    }

    for (std::string s : fr.readLines()){
        //USER_DB=data/database.csv
        if (s.empty()) continue;
        vector<string> tokens = split(s,'=');
        if (tokens.size() != 2){
            std::cerr << "EnvLoader: " <<
            "Formato incorrecto de archivo en la linea " << s <<
            " del archivo .env" << endl;
            return false;
        }
        // Se definen las 4 variables desde el archivo
        if (tokens.at(0) == "PATH_FILES_IN")
            PATH_FILES_IN = (string) tokens.at(1);
        else if (tokens.at(0) == "PATH_FILES_OUT")
            PATH_FILES_OUT = (string) tokens.at(1);
        else if (tokens.at(0) == "AMOUNT_THREADS")
            N_THREADS = (string) tokens.at(1);
        else if (tokens.at(0) == "EXTENSION")
            EXTENSION = (string) tokens.at(1);
        else {
            std::cerr << "EnvLoader: " << "Variable desconocida en archivo .env en la linea "
            << s << std::endl;
            return false; 
        }
    }

    if (PATH_FILES_IN.empty()){
        cerr << "EnvLoader: " << "No se encontro la variable de entorno PATH_FILES_IN" << endl;
        return false;
    }
    if (PATH_FILES_OUT.empty()){
        cerr << "EnvLoader: " << "No se encontro la variable de entorno PATH_FILES_OUT" << endl;
        return false;
    }
    if (EXTENSION.empty()){
        cerr << "EnvLoader: " << "No se encontro la variable de entorno EXTENSION" << endl;
        return false;
    }
    if (N_THREADS.empty()){
        cerr << "EnvLoader: " << "No se encontro la variable de entorno AMOUNT_THREADS" << endl;
        return false;
    }
    // Si se encontraron todas las variables
    loaded = true;
    return true;
}
EnvLoader* EnvLoader::getInstance(){
    if (instance == nullptr)
        instance = new EnvLoader();
    return instance;
}