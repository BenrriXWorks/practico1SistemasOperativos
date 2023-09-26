#include "FileReader.h"
#include "Functions.h"
#pragma once

class EnvLoader
{
private:
    static bool loaded;
    std::string PATH_FILES_IN, PATH_FILES_OUT, N_THREADS, EXTENSION;
    static EnvLoader* instance;
    EnvLoader(){};
public:
    static EnvLoader* getInstance();
    inline std::string getPathIn() const {return PATH_FILES_IN;};
    inline std::string getPathOut() const {return PATH_FILES_OUT;};
    inline std::string getNThreads() const {return N_THREADS;};
    inline std::string getExtension() const {return EXTENSION;};
    bool init(bool onlyFile);
    inline bool init(){return init(false);};
};