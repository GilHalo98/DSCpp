#pragma once
#include "comun.h"
#define coladefinida
#ifndef nodosimpledefinido
#include "nodos/nodoSimple.h"
#endif

template <class T>
class COLA : public EstructuraBase {
    public:
        // Contructor de clase.
        COLA(int=0);

        // Destructor de clase.
        ~COLA(void);

        // Realiza un push en la estructura.
        void push(T);

        // Realiza un pop a la estructura y reporta el dato eliminado.
        T pop(void);

        // Imprime los datos almacenados en la estructura.
        void debug(void);

        // Vacia la estructura.
        void dump(void);

    protected:

    private:
        // Puntero a la parte frontal de la estructura.
        nodoSimple<T>* punteroFrente = NULL;

        // Puntero a la parte tracera de la estructura.
        nodoSimple<T>* punteroCola = NULL;
};
#include "estructuras/cola.cpp"