#include "../../include/Menu.h"
using namespace std;

Menu* Menu::instance = nullptr;

Menu* Menu::getInstance() {
    if (!instance) {
        instance = new Menu();
    }
    return instance;
}

bool Menu::init(User* user) {
    // Implementa la inicialización aquí
    uint8_t optionNumber = 0;

    options.push_back(Option(optionNumber++, "SALIR", new ConcreteFunctionWrapper_0()));
    if (user->isAdmin()) 
        options.push_back(Option(optionNumber++, "CREAR USUARIO", new ConcreteFunctionWrapper_1()));
    options.push_back(Option(optionNumber++, "IMPRIMIR MSG PARA EL USUARIO", new ConcreteFunctionWrapper_2()));
    options.push_back(Option(optionNumber++, "ORDENAR VECTOR", new ConcreteFunctionWrapper_3()));


    return true; // Cambia esto según sea necesario
}

void Menu::display() {
    int opt = -1;
    Option* opcionSeleccionada = nullptr;
    ArgumentsLoader* args = ArgumentsLoader::getInstance();
    do {
        #ifndef _WIN32
            system("clear");
        #else
            system("cls");
        #endif

        // Obtener el PID del proceso padre
        pid_t pidPadre = getpid();

        cout << "SISTEMA 1 (PID = " << pidPadre << ")" << endl;

        printf("Bienvenido/a %s!\n", args->get_u().c_str());
        printf("Vector ingresado: {%s}\n",args->get_v().c_str());


        for (size_t i = 0; i < options.size(); ++i) {
            cout << i << ") " << options[i].getText() << endl;
        }

        if (opt != -1) {
            cout << "##############################################" << endl;

            cout << "Respuesta de la ejecución:" << endl;
            opcionSeleccionada->execute();

            cout << "##############################################" << endl;
        }
        printf("Por favor ingrese una opcion: ");

        // Solicita la selección al usuario y llama a la función correspondiente
        string line = "";
        getline(std::cin, line);
        strip(line);
        if (line.find_first_not_of("0123456789") != string::npos || line.empty()){
            opt = -1;
        }
        else {
            opt = stoi(line);
            if (opt >= 0 && opt < (int) options.size())
                opcionSeleccionada = &options.at(opt);
            else opt = -1;
        }

    } while (1);
}