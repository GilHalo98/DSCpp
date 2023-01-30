#define nododobledefinido
// Nodo doble, contiene dos punteros.
template <class T>
struct nodoDoble {
    // Dato del nodo.
    T dato;

    // Punteros del nodo.
    nodoDoble* siguiente = NULL;
    nodoDoble* anterior = NULL;
};