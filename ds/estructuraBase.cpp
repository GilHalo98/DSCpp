#include "comun.h"

ESTRUCTURA::EstructuraBase::EstructuraBase(int limiteDatos) {
    this->limiteDatos = limiteDatos;
    this->cantidadDatos = 0;
};

ESTRUCTURA::EstructuraBase::~EstructuraBase(void) {};

bool ESTRUCTURA::EstructuraBase::estaLlena(void) {
    // Retorna verdadero si la estructura esta al limite de
    // datos permitidos.
    if(this->limiteDatos < 0) {
        return false;
    } else {
        if(this->cantidadDatos < this->limiteDatos) {
            return false;
        }
    }

    return true;
};

bool ESTRUCTURA::EstructuraBase::estaVacia(void) {
    // Retorna verdadero si la estructura se encuentra vacia.
    if(this->cantidadDatos <= 0) {
        return true;
    }

    return false;
};

int ESTRUCTURA::EstructuraBase::getCantidadDatos(void) {
    // Retorna la cantidad de datos en la estructura.
    return this->cantidadDatos;
};

int ESTRUCTURA::EstructuraBase::getLimiteDatos(void) {
    // Retorna la cantidad de datos maxima.
    return this->limiteDatos;
};
