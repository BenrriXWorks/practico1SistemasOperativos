#include "FileStack.h"
#include "EnvLoader.h"
#include "Functions.h"
#include "FileWriter.h"
#include <thread>
#include <iostream>
#include <unordered_map>

class ThreadProcessor
{
private:
    std::thread* threads;
    // Realiza la funcion en cada thread.
    bool execute();
    uint8_t nThreads;
    FileStack *stack;

public:
    // Instancia el procesador de threads
    ThreadProcessor(FileStack &stack, uint8_t nThreads);
    // Comienza la ejecucion de los threads
    bool begin();
    // Destruye los punteros a threads
    ~ThreadProcessor() { delete[] threads; delete stack;};
};