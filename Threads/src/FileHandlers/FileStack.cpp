#include "../../include/FileStack.h"

FileReader* FileStack::next(){

    if (cola.empty())
        throw std::runtime_error("La cola esta vacia");
    FileReader *file = cola.at(--size);
    return file;
};


FileStack::FileStack(std::vector<std::string> listOfPaths){
    try{
        EnvLoader* env = EnvLoader::getInstance();
        size = listOfPaths.size();
        for (std::string s : listOfPaths){
            size_t dotPos = s.find_last_of('.');
            if (dotPos == std::string::npos){
                printf("El archivo {%s} no tiene una extension valida, saltando\n",s.c_str());
                --size;
                continue;
            }
            if (s.substr(dotPos+1) != env->getExtension()){
                printf("La extension del archivo {%s} no es la indicada por env {%s}, saltando\n", s.c_str(), env->getExtension().c_str());
                --size;
                continue;
            }
            FileReader *fr = new FileReader();
            if (!fr->open(s)){
                printf("El archivo en {%s} no ha podido ser leido. Saltando.\n",s.c_str());
                --size;
                continue;
            }
            cola.push_back(fr);        
        }
    }
    catch(...){
        throw std::runtime_error("Error al iniciar FileStack");
    }
};