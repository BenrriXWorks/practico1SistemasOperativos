#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

#pragma once

class FileHandler 
{
protected:
    std::wfstream fs;
public:
    bool checkFile(std::string path);
    virtual bool open(std::string path) = 0;
    inline void close() {fs.close();};
    bool checkDirectory(std::string path);
};
