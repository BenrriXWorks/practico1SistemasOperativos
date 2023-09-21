#include "../../include/Menu.h"
#include <iostream>
#include <cctype>
#include <algorithm>
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

    while(optionNumber <= 3){

        options.push_back(Option(optionNumber, "SALIR", new ConcreteFunctionWrapper_0()));
        optionNumber++;
        
        if (user->isAdmin()) 
            options.push_back(Option(optionNumber, "CREAR USUARIO", new ConcreteFunctionWrapper_1()));
        optionNumber++;
        options.push_back(Option(optionNumber, "IMPRIMIR MSG PARA EL USUARIO", new ConcreteFunctionWrapper_2()));
        optionNumber++;
        options.push_back(Option(optionNumber, "ORDENAR VECTOR", new ConcreteFunctionWrapper_3()));
        optionNumber++;
        }

    return true; // Cambia esto según sea necesario
}

void Menu::display() {
    // Obtener el PID del proceso padre
    pid_t pidPadre = getpid();

    cout << "SISTEMA 1 (PID = " << pidPadre << ")" << endl;
    cout << "##########################" << endl;

    cout << "respuesta de la ejecución:" << endl;
    cout << "--------------------------" << endl;//no se que se tiene que poner aqui o si son las barras

    cout << "##########################" << endl;
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i << options[i].getText() << endl;
    }

    // Solicita la selección al usuario y llama a la función correspondiente
    int seleccion;
    cout << "INGRESE OPCIÓN: ";
    while (!(cin >> seleccion) || seleccion > int(options.size()/3)-1) { //valida la opcion ingresada (que sea un numero y )
        cout << "Entrada inválida. Introduce un número válido: ";
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
    }
    Option& opcionSeleccionada = options[seleccion - 1];
    opcionSeleccionada.execute(); // Ejecuta la función correspondiente
    
}