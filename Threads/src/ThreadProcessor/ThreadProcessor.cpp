#include "../../include/ThreadProcessor.h"

using namespace std;


ThreadProcessor::ThreadProcessor(FileStack &stack, uint8_t nThreads) : 
    nThreads(nThreads), stack((&stack)) {
        uint8_t maxThreads = thread::hardware_concurrency();
        if (nThreads > maxThreads){
            printf("Se asignaron mas threads de los soportados por hardware, asignando %u en su lugar\n",maxThreads);
            nThreads = maxThreads;
        }
    };

void ThreadProcessor::execute(uint8_t threadId) {

    EnvLoader* env = EnvLoader::getInstance();

    while (!stack->empty()){

        FileReader* fr = stack->next();
        unordered_map<string,int> words;

        string consoleOutput = 
            string("El archivo ") + fr->getFullRoute() + string(" se esta procesando por el thread ")
            + to_string(threadId) + "\n";

        cout << consoleOutput << flush;

        while (!fr->eof()){
            string line = fr->readLine();
            
            for (string const& word : split(strip(line,'\n'),' ')){
                unordered_map<string,int>::iterator it = words.find(word);
                if (it == words.end()) words.emplace(word,1); else it->second++;
            }
        }
        FileWriter filewriter;
        if (!filewriter.open(env->getPathOut()+string("/")+fr->getFilename())){
            printf("ThreadProcessor (execute): No se pudo escribir en el archivo en {%s}", fr->getFullRoute().c_str());
        }

        for (const auto& p : words)
            filewriter << p.first.c_str() << ";" << p.second << "\n";

        filewriter.close();
    }

}

bool ThreadProcessor::begin() {

    if (stack->empty())
        return (printf("ThreadProcessor: No hay archivos para procesar.\n"),true);

    for (uint8_t i = 0; i < nThreads; i++) 
        threads.emplace_back([=]() { this->execute(i); });
    
    for (std::thread& t : threads) t.join();
    
    return true;
}