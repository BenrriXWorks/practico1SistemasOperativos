#include "include/EnvLoader.h"
#include "FileStack.h"
#include "ThreadProcessor.h"
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<std::string> archivosEnDirectorio(const fs::path& directorio) {
    std::vector<std::string> archivos;
    for (const auto& archivo : fs::directory_iterator(directorio)) {
        if (fs::is_regular_file(archivo)) {
            archivos.push_back(archivo.path().filename().string());
        }
    }
    return archivos;
}


class Main{
public:
    Main(){
        EnvLoader* envLoader = EnvLoader::getInstance();
        if (!envLoader->init(1)){
            printf("Main: No se pudo cargar las variables de entorno\n");
            throw std::runtime_error("No se pudieron cargar las variables de entorno");
        };
        FileStack fileStack(archivosEnDirectorio(envLoader->getPathIn()));
        
        int nthreads=1;
        try{
            nthreads = stoi(envLoader->getNThreads());
        }
        catch(...){
            printf("AMOUNT_THREADS (env) no detectado, iniciando con 1 Thread.\n");
        }
        ThreadProcessor tp(fileStack, nthreads);
        printf("hola\n");
    };

};

int main(){
    //try{
        Main();
    //}
    //catch(...){
        printf("HUbo un error critico.\n");
    //}
    return 0;
}