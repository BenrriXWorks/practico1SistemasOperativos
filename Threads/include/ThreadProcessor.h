#include "FileStack.h"
#include "EnvLoader.h"
#include "Functions.h"
#include <thread>

class ThreadProcessor
{
private:
    std::thread* threads;
    // Realiza la funcion en cada thread.
    bool execute();

    FileStack stack;

public:
    // Instancia el procesador de threads
    ThreadProcessor(FileStack &files, uint8_t nThreads);
    // Comienza la ejecucion de los threads
    bool begin();
    // Destruye los punteros a threads
    ~ThreadProcessor() { delete[] threads;};
};