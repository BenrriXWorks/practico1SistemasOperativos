#include "FileReader.h"
#include "vector"

class FileStack
{
private:
    std::vector<FileReader*> cola;
    
public:
    FileReader& next();
    FileStack(std::vector<std::string> listOfPaths);
    inline bool empty() {return cola.size()==0;};
};