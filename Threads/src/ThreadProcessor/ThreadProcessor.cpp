#include "../../include/ThreadProcessor.h"

using namespace std;

ThreadProcessor::ThreadProcessor(FileStack &stack, uint8_t nThreads) : 
    nThreads(nThreads), stack((&stack)) {};

void ThreadProcessor::execute() {

    while (!stack->empty()){
        FileReader* fr = stack->next();
        unordered_map<string,int> words;

        while (!fr->eof()){
            string line = fr->readLine();
            
            for (string const& word : split(strip(line,'\n'),' ')){
                unordered_map<string,int>::iterator it = words.find(word);
                if (it == words.end()) words.emplace(word,1); else it->second++;
            }
        }
        FileWriter filewriter;
        if (!filewriter.open(string("salida")+string("/")+fr->getFilename())){
            printf("ThreadProcessor (execute): No se pudo escribir en el archivo en {%s}", fr->getFullRoute().c_str());
        }

        for (const auto& p : words)
            filewriter << string(p.first);
        filewriter.close();
    }

}

bool ThreadProcessor::begin() {

    threads = vector<thread>();

    for (uint8_t i = 0; i < nThreads; i++) threads.emplace_back([this]() { this->execute(); });
    
    for (std::thread& t : threads) t.join();
    

    
    return true;
}