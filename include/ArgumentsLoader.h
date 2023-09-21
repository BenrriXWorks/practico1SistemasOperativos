#include <string>
#include "Functions.h"
#include <vector>
#include <getopt.h>
#pragma once

class ArgumentsLoader {
private:
    static bool loaded;
    static std::string i,o,u,f,t,v;
    static std::vector<int> v_vector;
    static ArgumentsLoader* instance;
    ArgumentsLoader(){};
public:
    static ArgumentsLoader* getInstance();
    static bool init(int argc,char** argv);

    inline std::string get_i(){return i;}
    inline std::string get_o(){return o;}
    inline std::string get_u(){return u;}
    inline std::string get_f(){return f;}
    inline std::string get_t(){return t;}
    inline std::string get_v(){return v;}
    inline std::vector<int> get_v_vector(){return v_vector;}
};