#include "FileReader.h"
#include "vector"

#pragma once

class FileStack
{
private:
    std::vector<FileReader*> cola;
    size_t size=0;
public:
    FileReader* next();
    FileStack(std::vector<std::string> listOfPaths);
    inline bool empty() {return size==0;};
    //~FileStack(){for (FileReader* ptr : cola) delete ptr;}
};