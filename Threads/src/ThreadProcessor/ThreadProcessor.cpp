#include "../../include/ThreadProcessor.h"


using namespace std;

ThreadProcessor::ThreadProcessor(FileStack &stack, uint8_t nThreads) {

    try{
        threads = new thread[nThreads];
    }
    catch(...){
        printf("ThreadProcessor: No se iniciarion los threads correctamente\n");
        throw std::runtime_error("Error al iniciar threads");
    }
    this->stack = &stack; 
}

void ThreadProcessor::execute() {
    while (!stack->empty()) {

        FileReader *fr = stack->next();

     /*if (!fr.open(path))
        return (printf("UserDB: No se pudo abrir el archivo en {%s}\n", path.c_str()),false);*/
        // aqui contamos palabras
        unordered_map<string, int> contadorPalabras;

        while(fr->eof()){
            string texto = fr->readLine();
            vector <string> lineas = split(texto,' ');
            for(string linea: lineas){
                //aca le quitamos los espacios.. los caracteres raros.. y lo pasamos a minuscula
                contadorPalabras[linea]++;
            }
        }
        // aqui se creara el archivo

        FileWriter fw;
        string path = "salida/"; // Leer desde el entorno
        //aqui le debo agregar la ruta de salida
        if(!fw.open(path+fr->getFilename())){
            printf("ThreadProcessor: No se pudo crear el archivo en {%s}\n", path.c_str());
            continue;
        }

        for (const auto &entry : contadorPalabras) {
            fw.writeLine(entry.first + string(",") + to_string(entry.second));
        }
        fr->close();
        fw.close();
        cout << "Archivo " << fr->getFullRoute() << ", procesado por el thread " << this_thread::get_id() << endl << std::flush;
        
    }
}

bool ThreadProcessor::begin() {

    for (uint8_t i = 0; i < nThreads; i++) {
        threads[i] = std::thread([this]() { this->execute(); });
    }

    for (uint8_t i = 0; i < nThreads; i++) {
        threads[i].join(); // espera a que terminen los procesos
    }

    return true;
}
