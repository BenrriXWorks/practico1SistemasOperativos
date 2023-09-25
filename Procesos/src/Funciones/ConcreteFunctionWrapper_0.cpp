#include "../../include/ConcreteFunctionWrapper_0.h"

bool ConcreteFunctionWrapper_0 :: execute(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("Adios!\n");
    exit(EXIT_SUCCESS);
}