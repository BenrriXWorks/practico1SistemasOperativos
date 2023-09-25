#include "../../include/ConcreteFunctionWrapper_2.h"

bool ConcreteFunctionWrapper_2 :: execute(){
    ArgumentsLoader* al = ArgumentsLoader::getInstance();
    std::string comandoPython = "python3 saluda.py " + al->get_u();
    int resultado = system(comandoPython.c_str());
    return resultado == 0;
}