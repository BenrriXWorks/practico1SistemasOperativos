#include "../../include/FileStack.h"

FileReader& FileStack::next(){
    FileReader *file = cola.back();
    cola.pop_back();
    return (*file);
};


FileStack::FileStack(std::vector<std::string> listOfPaths){

    for (std::string s : listOfPaths){
        FileReader *fr = &FileReader();
        if (!fr->open(s))
            printf("El archivo en {%s} no ha podido ser leido. Saltando.\n",s);
        cola.push_back(fr);        
    }
    
};
