#include "ArgumentsLoader.h"
#include "Option.h"
#include "ConcreteFunctionWrapper_0.h"
#include "ConcreteFunctionWrapper_1.h"
#include "ConcreteFunctionWrapper_2.h"
#include "ConcreteFunctionWrapper_3.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <sys/types.h>
#include <limits>
#include "User.h"
#include <vector>
#include <unistd.h> 
#pragma once

class Menu {
private:
    static Menu* instance;
    std::vector<Option> options; 
    Menu(){};

public:
    static Menu* getInstance();
    bool init(User* user);
    void display();
};