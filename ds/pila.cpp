#include "comun.h"
#include "estructuras.h"

// Constructor de clase.
template <class T>
ESTRUCTURA::PILA<T>::PILA(int limiteDatos) {
    // Cantida de datos maixmo de la estructura.
    this->limiteDatos = limiteDatos;

    // Cantidad de datos actual de la estructura.
    this->cantidadDatos = 0;

    // Puntero al elemento superior de la estructura.
    this->punteroSuperior = NULL;
};

// Destructor de clase.
template <class T>
ESTRUCTURA::PILA<T>::~PILA(void) {};

// Agrega un elemento a la estructura.
template <class T>
void ESTRUCTURA::PILA<T>::push(T dato) {
    // Si la pila no esta llena, agregamos el nodo.
    if(!this->estaLlena()) {
        // Se crea un nuevo nodo.
        nodoSimple<T>* nodoNuevo = new nodoSimple<T>();

        // Se asigna el index y el dato al nodo.
        nodoNuevo->dato = dato;

        // Si la pila no esta vacia, se conecta el nodo a
        // la estructura.
        if(!this->estaVacia()) {
            nodoNuevo->siguiente = this->punteroSuperior;
        }
 
        // Actualizamos el puntero superior.
        this->punteroSuperior = nodoNuevo;

        // Aumentamos el conteo en 1.
        this->cantidadDatos++;
    }
};

// Retira un elemento de la estructura.
template <class T>
T ESTRUCTURA::PILA<T>::pop(void) {
    // Mientras que la pila no este vacia.
    if(!this->estaVacia()) {
        // Almacena una varible con el dato del nodo.
        T dato;

        // Si hay mas de un elemento, se instancia un puntero auxiliar.
        nodoSimple<T>* punteroNodoRemovido = this->punteroSuperior;

        // Movemos el nodo superior una posicion.
        this->punteroSuperior = this->punteroSuperior->siguiente;

        // Recuperamos el dato del nodo a remover.
        dato = punteroNodoRemovido->dato;

        // se elimina el nodo en el puntero auxiliar.
        delete punteroNodoRemovido;

        // Disminuimos en uno el conteo de elementos.
        this->cantidadDatos--;

        // Retornamos los datos recuperados.
        return dato;

    } else {
        // Si la pila esta vacia, retorna NULL;
        return (T)NULL;
    }
};

// Funcion para verificar el funcionamiento de la estructura.
template <class T>
void ESTRUCTURA::PILA<T>::debug(void) {
    // Si la estructura no esta vacia, se imprime
    // su contendio.
    if(!this->estaVacia()) {
        nodoSimple<T>* punteroAux = this->punteroSuperior;

        while(punteroAux->siguiente != NULL) {
            std::cout<<punteroAux->dato<<", ";
            punteroAux = punteroAux->siguiente;
        }
        std::cout<<punteroAux->dato<<std::endl;
    }
    // Sino se imprime que esta vacia.
    else {
        std::cout<<"Vacia!"<<std::endl;
    }
};

template <class T>
void ESTRUCTURA::PILA<T>::dump(void) {
    // Vacia todos los nodos de la estructura.
    while(!this->estaVacia()) {
        this->pop();
    }
};
