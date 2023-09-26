#include "include/EnvLoader.h"
#include "include/FileStack.h"
#include "include/ThreadProcessor.h"
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

std::vector<std::string> archivosEnDirectorio(const fs::path& directorio) {
    std::vector<std::string> archivos;
    try {
        if (fs::exists(directorio) && fs::is_directory(directorio)) {
            for (const auto& archivo : fs::directory_iterator(directorio)) {
                if (fs::is_regular_file(archivo)) {
                    // Obtén el nombre del archivo
                    std::string nombreArchivo = archivo.path().filename().string();
                    // Concatena la ruta relativa al nombre del archivo
                    std::string rutaRelativa = directorio / nombreArchivo;
                    archivos.push_back(rutaRelativa);
                }
            }
        } else {
            std::cerr << "El directorio no existe o no es válido: " << directorio << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& ex) {
        std::cerr << "Error al abrir el directorio: " << ex.what() << std::endl;
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
            tp.begin();
            printf("hola\n");


    };

};

int main(){
    
    Main();
    return 0;
}