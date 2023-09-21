#include <string>
#include "Functions.h"
#include <vector>
#include <getopt.h>
#pragma once

class ArgumentsLoader {
private:
    static bool loaded;
    static std::string u,p,v;
    static std::vector<int> v_vector;
    static ArgumentsLoader* instance;
    ArgumentsLoader(){};
public:
    static ArgumentsLoader* getInstance();
    static bool init(int argc,char** argv);

    inline std::string get_p(){return p;}
    inline std::string get_u(){return u;}
    inline std::string get_v(){return v;}
    inline std::vector<int> get_v_vector(){return v_vector;}
};