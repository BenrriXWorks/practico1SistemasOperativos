#include "../../include/FileStack.h"

FileReader* FileStack::next(){

    if (cola.empty())
        throw std::runtime_error("La cola esta vacia");

    FileReader *file = cola.back();
    cola.pop_back();
    return file;
};


FileStack::FileStack(std::vector<std::string> listOfPaths){

    for (std::string s : listOfPaths){
        FileReader *fr = new FileReader();
        if (!fr->open(s)){
            printf("El archivo en {%s} no ha podido ser leido. Saltando.\n",s.c_str());
        }
        cola.push_back(fr);        
    }

};