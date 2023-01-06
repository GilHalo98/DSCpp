#include "DS.h"

template <class T>
ESTRUCTURAS::PILA<T>::PILA(int capacidad) {
	// Por default, la capacidad es 0, esto indica
	// que la pila no tiene un maximo de elementos.
	this->capacidadDatos = capacidad;

	// Cantidad de datos actual en la pila.
	this->cantidadDatos = 0;

	// Puntero al elemento superior de la pila.
	this->punteroSuperior = NULL;
}

template <class T>
ESTRUCTURAS::PILA<T>::~PILA(void) {}

template <class T>
bool ESTRUCTURAS::PILA<T>::push(T dato) {
	// Agregamos un nodo a la pila.

	// Verificamos que la pila no este llena.
	if(!this->estaLlena()) {
		// Creamos un nuevo nodo.
		NodoSimple<T>* nuevoNodo = new NodoSimple<T>();

		// Agregamos el dato al nodo.
		nuevoNodo->dato = dato;

		// Verificamos si la pila esta vacia.
		if(this->estaVacia()) {
			// Asignamos el puntero superior al nuevo nodo.
			this->punteroSuperior = nuevoNodo;
		} else {
			// Colocamos el nuevo nodo
			// encima del puntero superior
			nuevoNodo->siguiente = this->punteroSuperior;

			// Asignamos el nuevo nodo
			// como el puntero superor.
			this->punteroSuperior = nuevoNodo;
		}

		// Aumentamos el conteo de datos.
		this->cantidadDatos++;

		return true;
	}
	return false;
}

template <class T>
T ESTRUCTURAS::PILA<T>::pop() {
	// Remueve un dato de la pila.
	if(!this->estaVacia()) {
		// Dato que se recupera al eliminar el nodo.
		T dato;

		// Nodo a eliminar.
		NodoSimple<T>* nodoRemovido = this->punteroSuperior;

		// El puntero superior se mueve al siguiente nodo.
		this->punteroSuperior = this->punteroSuperior->siguiente;

		// Dato recuperado.
		dato = nodoRemovido->dato;

		// Liberamos la memoria usada.
		delete nodoRemovido;

		// Disminuye la cantida de datos en la pila.
		this->cantidadDatos--;

		// Retornamos el dato.
		return dato;
	}

	return (T)NULL;
}

template <class T>
bool ESTRUCTURAS::PILA<T>::dump() {
	// Vacia la pila.
	while(this->cantidadDatos >0) {
		this->pop();
	}

	return true;
}

template <class T>
int ESTRUCTURAS::PILA<T>::getCantidadDatos() {
	// Retorna la cantida de datos actual en
	// la pila.
	return this->cantidadDatos;
}

template <class T>
int ESTRUCTURAS::PILA<T>::getCapacidad() {
	// Retorna la capacidad de la pila
	// si retorna 0 no hay un limite.
	return this->capacidadDatos;
}

template <class T>
bool ESTRUCTURAS::PILA<T>::estaVacia() {
	// Retorna si la pila esta vacia.
	if(this->cantidadDatos == 0) {
		return true;
	}

	return false;
}

template <class T>
bool ESTRUCTURAS::PILA<T>::estaLlena() {
	// Retorna si la pila esta llena.
	if(this->capacidadDatos > 0) {
		if(this->cantidadDatos == this->capacidadDatos) {
			return true;
		}
	}

	return false;
}

template <class T>
void ESTRUCTURAS::PILA<T>::debug() {
	if(!this->estaVacia()) {
		NodoSimple<T>* punteroAux = this->punteroSuperior;

		while(punteroAux->siguiente != NULL) {
			std::cout<<punteroAux->dato<<", ";
			punteroAux = punteroAux->siguiente;
		}
		std::cout<<punteroAux->dato<<std::endl;
	} else {
		std::cout<<"Vacia!"<<std::endl;
	}
}
