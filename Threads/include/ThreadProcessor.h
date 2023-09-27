#include "FileStack.h"
#include "EnvLoader.h"
#include "Functions.h"
#include "FileWriter.h"
#include <thread>
#include <iostream>
#include <unordered_map>

#pragma once

class ThreadProcessor
{
private:
    std::vector<std::thread> threads;
    // Realiza la funcion en cada thread.
    void execute(uint8_t threadId);
    uint8_t nThreads;
    FileStack *stack;

public:
    // Instancia el procesador de threads
    ThreadProcessor(FileStack &stack, uint8_t nThreads);
    // Comienza la ejecucion de los threads
    bool begin();

};