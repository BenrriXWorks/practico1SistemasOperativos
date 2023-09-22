#include "../../include/EnvLoader.h"
using namespace std;

EnvLoader* EnvLoader::instance = nullptr;
bool EnvLoader::loaded = false;

bool EnvLoader::init(bool onlyFile){
    
    if (loaded==true)
        return (printf("EnvLoaded: Error, esta clase ya ha sido iniciada"),false);
    

    uint8_t conditionsMeet = 0;
    char* ENV_USER_DB;
    if (!onlyFile) {
        ENV_USER_DB =  getenv("USER_DB");
        if (ENV_USER_DB != nullptr) ++conditionsMeet; 
    }
    if (conditionsMeet == 1) {
        userDB = (string) ENV_USER_DB;
        return true;
    }
    else {
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
            if (tokens.at(0) == "USER_DB")
                userDB = (string) tokens.at(1);
            else {
                std::cerr << "EnvLoader: " << "Variable desconocida en archivo .env en la linea "
                << s << std::endl;
                return false; 
            }
        }
    }
    if (userDB.empty()){
        cerr << "EnvLoader: " << "No se encontro la variable de entorno userDB" << endl;
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