#include "FunctionWrapper.h"
#include <string>
#pragma once

class Option {

private:
    FunctionWrapper* func;
    std::string texto;
    uint8_t id;

public:
    Option(uint8_t id, std::string texto, FunctionWrapper* func) : id(id), texto(texto), func(func) {}
    inline std::string getText() {return texto;};
    // Devuelve falso si no se ejecuto la orden correctamente
    inline bool execute() {return func->execute();};
    inline uint8_t getId() {return id;};
    // Retorna si el id de este objeto es menor
    inline bool operator<(const Option& otherOpt) {return this->id < otherOpt.id;};

};