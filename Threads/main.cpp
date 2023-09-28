#include "include/EnvLoader.h"
#include "include/FileStack.h"
#include "include/ThreadProcessor.h"
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

class Main{

private:
    std::vector<std::string> archivosEnDirectorio(const fs::path& directorio) {
        std::vector<std::string> archivos;
        try {
            if (fs::exists(directorio) && fs::is_directory(directorio)) {
                for (const auto& archivo : fs::directory_iterator(directorio)) 
                    if (archivo.is_regular_file()) 
                        archivos.push_back(archivo.path().string());
            }
            else 
                std::cerr << "Main (archivosEnDirectorio): El directorio no existe o no es válido: " << directorio << std::endl;
        } 
        catch (const std::filesystem::filesystem_error& ex) {
            std::cerr << "Error al abrir el directorio: " << ex.what() << std::endl;
        }
        return archivos;
    }
    std::vector<std::string> processRoute(std::vector<std::string> routes){
        std::vector<std::string> processed_nombres;
        for (std::string r : routes){
            processed_nombres.push_back(std::string("Processed/") + r.substr(r.find_last_of("\\/") + 1));
        }
        return processed_nombres;
    }

public:
    Main(){

        EnvLoader* envLoader = EnvLoader::getInstance();
        if (!envLoader->init(1)){
            printf("Main: No se pudo cargar las variables de entorno\n");
            throw std::runtime_error("No se pudieron cargar las variables de entorno");
        };

        std::string call = "python3 normalizaTexto.py ";
        std::vector<std::string> archivosDirectorio = archivosEnDirectorio(envLoader->getPathIn());
        for (std::string s : archivosDirectorio)
            call += s + std::string(" ");

        if (system(call.c_str()) != 0){
            throw std::runtime_error("No se pudieron processar (normalizar) los archivos\n");
        };
        
        FileStack fileStack(processRoute(archivosDirectorio));
        int nthreads=1;
        if (envLoader->getNThreads().find_first_not_of("0123456789") != std::string::npos)
            throw std::runtime_error("La cantidad de threads contiene caracteres invalidos\n");
        if (envLoader->getPathIn() == "Processed" || envLoader->getPathOut() == "Processed"
            || envLoader->getPathIn().find("src") != std::string::npos || envLoader->getPathOut().find("src") != std::string::npos
            || envLoader->getPathIn() == "include" || envLoader->getPathOut() == "include"
            || envLoader->getPathIn().find("compiled") != std::string::npos || envLoader->getPathOut().find("compiled") != std::string::npos)
                throw std::runtime_error("No puedes acceder a carpetas protegidas por el programa\n");
        if (envLoader->getPathIn() == envLoader->getPathOut())
            throw std::runtime_error("Main: La carpeta de entrada no puede ser la de salida\n");
        nthreads = stoi(envLoader->getNThreads());
        ThreadProcessor tp(fileStack, nthreads);
        tp.begin();


    };

};

int main(){
    

    Main();

    return 0;
}