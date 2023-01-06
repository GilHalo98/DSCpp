/*
 * Nodos de las estructuras de datos.
 * */

template <class T>
struct NodoSimple {
	// Dato del nodo.
	T dato;

	// Puntero siguiente del nodo.
	NodoSimple* siguiente = NULL;
};
