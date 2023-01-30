#pragma once
#include "comun.h"
#define listadobledefinida
#ifndef nododobledefinido
#include "nodos/nodoDoble.h"
#endif

template <class T>
class LISTA_DOBLE : public EstructuraBase {
    public:
        // Constructor de clase.
        LISTA_DOBLE(int=0);

        // Destructor de clase.
        ~LISTA_DOBLE(void);

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
        nodoDoble<T>* getPunteroInicio(void);

        // Retorna el puntero fin de la estructura.
        nodoDoble<T>* getPunteroFin(void);

        // Retorna un puntero a un elemento dado un index.
        nodoDoble<T>* getPunteroElemento(int);

    protected:

    private:
        // Puntero de inicion de la estructura.
        nodoDoble<T>* punteroInicio;

        // Puntero de fin de la estructura.
        nodoDoble<T>* punteroFin;
};
#include "estructuras/listaDoble.cpp"