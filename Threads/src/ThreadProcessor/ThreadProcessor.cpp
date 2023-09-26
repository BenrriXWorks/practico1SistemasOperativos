#include "../../include/ThreadProcessor.h"
#include <iostream>

using namespace std;

ThreadProcessor::ThreadProcessor(FileStack &files, uint8_t nThreads) {
    threads = new thread[nThreads];
    stack = &files; 
}
//inline bool empty() {return cola.size()==0;};
bool ThreadProcessor::execute() {
    while (!stack->empty()) {

        FileReader fr = stack->next();

    /*if (!fr.open(path))
        return (printf("UserDB: No se pudo abrir el archivo en {%s}\n", path.c_str()),false);*/
        if (!fr.open(fr.getFileName)) {
            return (printf("ThreadProcessor: No se pudo abrir el archivo en {%s}\n", fr.getFileName.c_str()),false);
        }
        // aqui contamos palabras
        unordered_map<string, int> contadorPalabras;

        while(fr.eof()){
            string texto = fr.readLine();
            vector <string> lineas = split(texto," ");
            for(string linea: lineas){
                //aca le quitamos los espacios.. los caracteres raros.. y lo pasamos a minuscula
                contadorPalabras[linea]++;
            }
        }
        // aqui se creara el archivo

        FileWriter fw;
        //aqui le debo agregar la ruta de salida
        if(!fw.open(path)){
            return (printf("ThreadProcessor: No se pudo crear el archivo en {%s}\n", path.c_str()),false);
        }

        for (const auto &entry : contadorPalabras) {
            fw.writeLine(entry.first + "," + entry.second);
        }
        fr.close();
        fw.close();


        cout << "Archivo " << fr.getFullRoute << ", procesado por el thread " << this_thread::get_id() << endl;
    }
    return true;
}

bool ThreadProcessor::begin() {
    if (threads == nullptr) {
        return (printf("ThreadProcessor: Los threads no se inicializaron correctamente {%s}\n",line.c_str()));
        return false; // si algo no funciona
        pr
    }

    for (uint8_t i = 0; i < nThreads; i++) {
        threads[i] = thread(&ThreadProcessor->execute(), this);
    }

    for (uint8_t i = 0; i < nThreads; i++) {
        threads[i].join(); // espera a que terminen los procesos
    }

    return true;
}
