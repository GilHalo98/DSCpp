#define nodobinariodefinido
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