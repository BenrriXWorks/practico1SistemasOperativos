#include "../../include/ConcreteFunctionWrapper_3.h"
using namespace std;

bool ConcreteFunctionWrapper_3::execute(){
    ArgumentsLoader* args = ArgumentsLoader::getInstance();
    string vector = args->get_v();
    if (strip(vector).empty()){
        return (printf("No se ingreso un vector\n"),false);
    }
    // Construir el comando para llamar al script de Python
    string comandoPython = "python3 ordenaVector.py \"" + vector + "\"";

    // Ejecutar el comando de Python
    int resultado = system(comandoPython.c_str());

    // Verificar si la ejecución fue exitosa
    return resultado == 0;
}

    