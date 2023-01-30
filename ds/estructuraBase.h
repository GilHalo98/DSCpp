#pragma once
#define estructurabasedefinida

class EstructuraBase {
    public:
        // Constructor de la estructura, por default la cantidad
        // de datos maxima no tiene limite.
        EstructuraBase(int=0);

        // Destructor de la estructura.
        ~EstructuraBase(void);

        // Retorna el limite de los datos en la estructura.
        int getLimiteDatos(void);

        // Retorna la cantidad actual de datos en la estructura.
        int getCantidadDatos(void);

        // Indica si la estructura esta vacia.
        bool estaVacia(void);

        // Indica si la estructura esta llena.
        bool estaLlena(void);

    protected:
        // Limite de datos en la estructura.
        int limiteDatos;

        // Cantidad de datos actual en la estructura.
        int cantidadDatos;

    private:
};
#include "estructuras/estructuraBase.cpp"