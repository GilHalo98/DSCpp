#include "comun.h"

template <class T>
ESTRUCTURA::EstructuraBase<T>::EstructuraBase(int limiteDatos) {
    this->limiteDatos = limiteDatos;
    this->cantidadDatos = 0;
};

template <class T>
ESTRUCTURA::EstructuraBase<T>::~EstructuraBase(void) {};

template <class T>
bool ESTRUCTURA::EstructuraBase<T>::estaLlena(void) {
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

template <class T>
bool ESTRUCTURA::EstructuraBase<T>::estaVacia(void) {
    // Retorna verdadero si la estructura se encuentra vacia.
    if(this->cantidadDatos <= 0) {
        return true;
    }

    return false;
};

template <class T>
int ESTRUCTURA::EstructuraBase<T>::getCantidadDatos(void) {
    // Retorna la cantidad de datos en la estructura.
    return this->cantidadDatos;
};

template <class T>
int ESTRUCTURA::EstructuraBase<T>::getLimiteDatos(void) {
    // Retorna la cantidad de datos maxima.
    return this->limiteDatos;
};
