#pragma once
#include "comun.h"
#define listadefinida
#ifndef nodosimpledefinido
#include "nodos/nodoSimple.h"
#endif

template <class T>
class LISTA : public EstructuraBase {
    public:
        // Constructor de clase de la estructura.
        LISTA(int=0);

        // Destructor de clase de la estructura.
        ~LISTA(void);

        // Agrega un elemento en el index dado.
        void push(T, int=0);

        // Elimina un elemento en el index dado.
        T pop(int=0);

        // Imprime los datos almacenados en la estructura.
        void debug(void);

        // Vacia la estructura.
        void dump(void);

        // Accede a un dato en un index dado con el operador
        // de acceso de arreglos.
        T operator [] (int);

        // Intercambia dos datos de posicion.
        void intercambiarDatos(int, int);

        // Retorna el puntero de inicio de la estructura.
        nodoSimple<T>* getPunteroInicio(void);

        // Retorna el puntero fin de la estructura.
        nodoSimple<T>* getPunteroFin(void);

        // Retorna un puntero a un elemento dado un index.
        nodoSimple<T>* getPunteroElemento(int);

    protected:

    private:
        // Puntero de inicio de la estructura.
        nodoSimple<T>* punteroInicio;

        // Puntero fin de la estructura.
        nodoSimple<T>* punteroFin;
};
#include "estructuras/lista.cpp"