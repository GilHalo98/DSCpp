#pragma once
#include "comun.h"
#define piladefinida
#ifndef nodosimpledefinido
#include "nodos/nodoSimple.h"
#endif

template <class T>
class PILA : public EstructuraBase {
    public:
        // Constructor de clase.
        PILA(int=0);

        // Destructor de clase.
        ~PILA(void);

        // Realiza un push a la estructura con el dato de tipo T.
        void push(T);

        // Realiza un pop a la estructura y retorna el dato de tipo
        // T.
        T pop(void);

        // Elimina todos los datos de la estructura.
        void dump(void);

        // Imprime en consola los datos de la estructura.
        void debug(void);

    protected:

    private:
        // Puntero a la parte superior de la estructura.
        nodoSimple<T>* punteroSuperior;
};
#include "estructuras/pila.cpp"