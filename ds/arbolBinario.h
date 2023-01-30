#pragma once
#include "comun.h"
#define arbolbinariodefinido
#ifndef nodobinariodefinido
#include "nodos/nodoBinario.h"
#endif

template <class T>
class ARBOL_BINARIO : public EstructuraBase {
    public:
        // Constructor de clase.
        ARBOL_BINARIO(int=0);

        // Destructor de clase.
        ~ARBOL_BINARIO(void);

        // Agrega un elemento a la estructura.
        void push(T);

        // Remueve en orden un dato de la estructura.
        T pop(bool=true);

        // Vacia la estructura.
        void dump(void);

        // Retorna el puntero raiz de la estructura.
        nodoBinario<T>* getPunteroRaiz(void);

    protected:

    private:
        // Puntero al elemento raiz de la estructura.
        nodoBinario<T>* punteroRaiz;

        // Busca una rama de manera recursiva en la que
        // se agregara un elemento.
        nodoBinario<T>* buscarRama(nodoBinario<T>*, nodoBinario<T>*);

        // Indica si un nodo es hoja.
        bool esHoja(nodoBinario<T>*);

        // Busca el elemento mayor de la estructura.
        nodoBinario<T>* buscarMayorElemento(nodoBinario<T>*);

        // Busca el elemento menor de la estructura.
        nodoBinario<T>* buscarMenorElemento(nodoBinario<T>*);
};
#include "estructuras/arbolBinario.cpp"