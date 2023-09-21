#include <unordered_map>
#include "FileReader.h"
#include "Functions.h"
#pragma once

class EnvLoader
{
private:
    static bool loaded;
    std::string userDB;
    std::string profileDB;
    std::string menuDB;
    std::string languageDB;
    static EnvLoader* instance;
    EnvLoader(){};
public:
    static EnvLoader* getInstance();
    inline std::string getUserDB_path() const {return userDB;};
    inline std::string getProfileDB_path() const {return profileDB;};
    inline std::string getMenuDB_path() const {return menuDB;};
    inline std::string getLanguageDB_path() const {return languageDB;};
    bool init(bool onlyFile);
    inline bool init(){return init(false);};
};