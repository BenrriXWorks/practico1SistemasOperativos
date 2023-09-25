#include "FileReader.h"
#include "vector"

class FileStack
{
private:
    std::vector<FileReader> cola;
    FileStack* instance;
public:
    FileReader next();
    FileStack* getInstance();
    bool init(std::vector<std::string> listOfPaths);
};