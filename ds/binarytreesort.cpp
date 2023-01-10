#include "comun.h"

// Binary Tree sort para listas.
template <class T>
void ORDENAMIENTO::binaryTreeSort(
    ESTRUCTURA::LISTA<T>* lista,
    bool ascendente
) {
    // Instanciamos el arbol auxiliar.
    ESTRUCTURA::ARBOL_BINARIO<int> arbol = ESTRUCTURA::ARBOL_BINARIO<int>(
        lista->get_cantidad_datos()
    );

    // Mientras que la lista tenga elementos, los removemos y
    // los agregamos al arbol.
    T dato;
    while(!lista->esta_vacia()) {
        dato = lista->pop();
        arbol.push(dato);
    }

    // Mientras el arbol tenga elementos, los removemos en orden y
    // los agregamos a la lista.
    while(!arbol.esta_vacia()) {
        dato = arbol.pop(ascendente);
        lista->push(dato);
    }

    delete arbol;
}

// Binary Tree sort para listas doble.
template <class T>
void ORDENAMIENTO::binaryTreeSort(
    ESTRUCTURA::LISTA_DOBLE<T>* lista,
    bool ascendente
) {
    // Instanciamos el arbol auxiliar.
    ESTRUCTURA::ARBOL_BINARIO<int> arbol = ESTRUCTURA::ARBOL_BINARIO<int>(
        lista->get_cantidad_datos()
    );

    // Mientras que la lista tenga elementos, los removemos y
    // los agregamos al arbol.
    T dato;
    while(!lista.esta_vacia()) {
        dato = lista->pop();
        arbol.push(dato);
    }

    // Mientras el arbol tenga elementos, los removemos en orden y
    // los agregamos a la lista.
    while(!arbol.esta_vacia()) {
        dato = arbol.pop(ascendente);
        lista->push(dato);
    }

    delete arbol;
}