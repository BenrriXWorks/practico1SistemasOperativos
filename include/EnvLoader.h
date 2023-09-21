#include <unordered_map>
#include "FileReader.h"
#include "Functions.h"
#pragma once

class EnvLoader
{
private:
    static bool loaded;
    std::string userDB;
    static EnvLoader* instance;
    EnvLoader(){};
public:
    static EnvLoader* getInstance();
    inline std::string getUserDB_path() const {return userDB;};
    bool init(bool onlyFile);
    inline bool init(){return init(false);};
};