#include "ArgumentsLoader.h"
#include "Option.h"
#include "ConcreteFunctionWrapper_0.h"
#include "ConcreteFunctionWrapper_1.h"
#include "ConcreteFunctionWrapper_2.h"
#include "ConcreteFunctionWrapper_3.h"
#include "User.h"
#pragma once

class Menu {
private:
    static Menu* instance;
    Menu(){};

public:
    Menu* getInstance();
    bool init(User* user);
    void display();
};