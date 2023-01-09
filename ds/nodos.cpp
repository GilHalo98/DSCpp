/*
 * Nodos que usan las estructuras de datos
 * estos nodos estan contruidos por templates.
*/

// Nodo simple, contiene un puntero.
template <class T>
struct nodoSimple {
    // Dato que almacena el nodo.
    T dato;

    // Punteros usados para estructurar nodos.
    nodoSimple* siguiente = NULL;
};

// Nodo para los arboles binarios.
template <class T>
struct nodoBinario {
    // Dato del nodo.
    T dato;

    // Punteros del nodo.
    nodoBinario* nodoPadre = NULL;
    nodoBinario* hijoDerecha = NULL;
    nodoBinario* hijoIzquierda = NULL;
};

// Nodo doble, contiene dos punteros.
template <class T>
struct nodoDoble {
    // Dato del nodo.
    T dato;

    // Punteros del nodo.
    nodoDoble* siguiente = NULL;
    nodoDoble* anterior = NULL;
};
