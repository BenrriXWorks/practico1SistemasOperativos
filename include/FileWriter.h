#include "FileHandler.h"
#include <string>
#include <fstream>
#include <vector>

class FileWriter : public FileHandler 
{
public:
    bool writeLine(const std::string line);
    bool writeLines(const std::vector<std::string> lines);
    bool write(const std::string text);
    bool open(const std::string path);
    bool openAppend(const std::string path);
    bool close();
    FileWriter& operator<<(const std::string& s);
};