#define nodosimpledefinido
// Nodo simple, contiene un puntero.
template <class T>
struct nodoSimple {
    // Dato que almacena el nodo.
    T dato;

    // Punteros usados para estructurar nodos.
    nodoSimple* siguiente = NULL;
};