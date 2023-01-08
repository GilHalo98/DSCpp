#include "comun.h"
#include "estructuras.h"

// Constructor de clase.
template <class T>
ESTRUCTURA::COLA<T>::COLA(int limiteDatos) {
    // Cantida de datos maixmo de la estructura.
    this->limiteDatos = limiteDatos;

    // Cantidad de datos actual de la estructura.
    this->cantidadDatos = 0;

    // Los punteros son inicializados en nulo.
    this->punteroCola = NULL;
    this->punteroFrente = NULL;
};

// Destructor de clase.
template <class T>
ESTRUCTURA::COLA<T>::~COLA(void) {};

// Agrega un elemento a la estructura.
template <class T>
void ESTRUCTURA::COLA<T>::push(T dato) {
    // Si la estructura no esta llena, se pueden agregar
    // datos a esta.
    if(!this->estaLlena()) {
        // Se crea un nuevo nodo.
        nodoSimple<T>* nodoNuevo = new nodoSimple<T>;

        // Se asigna el dato al nodo.
        nodoNuevo->dato = dato;

        // Si la estructura esta vacia.
        if(this->estaVacia()) {
            // El puntero inferior apunta al nuevo
            // nodo.
            this->punteroFrente = nodoNuevo;

        } else {
            // Si la estrucura no esta vacia
            // El puntero cola siguiente es vinculado
            // al nuevo nodo.
            this->punteroCola->siguiente = nodoNuevo;
        }

        // El puntero superior apunta al nuevo nodo.
        this->punteroCola = nodoNuevo;

        // Incrementa la cantidad de datos contada.
        this->cantidadDatos++;
    }
};

// Retira un elemento de la estructura.
template <class T>
T ESTRUCTURA::COLA<T>::pop(void) {
    // Mientras que la cola no este vacia.
    if(!this->estaVacia()) {
        // Almacena una varible con el dato del nodo.
        T dato;

        // Si hay mas de un elemento, se instancia un puntero auxiliar.
        nodoSimple<T>* punteroNodoRemovido = this->punteroFrente;

        // Movemos el puntero frente una posicion.
        this->punteroFrente = this->punteroFrente->siguiente;

        // Recuperamos el dato del nodo removido.
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
void ESTRUCTURA::COLA<T>::debug(void) {
    // Si la estructura no esta vacia, se imprime
    // su contendio.
    if(!this->estaVacia()) {
        nodoSimple<T>* punteroAux = this->punteroFrente;

        while(punteroAux != NULL) {
            std::cout<<punteroAux->dato<<", ";
            punteroAux = punteroAux->siguiente;
        }
        std::cout<<std::endl;
    }
    // Sino se imprime que esta vacia.
    else
    {
        std::cout<<"Vacia!"<<std::endl;
    }
};

// La funcion vacia la estructura de todo nodo existente.
template <class T>
void ESTRUCTURA::COLA<T>::dump(void) {
    while(!this->estaVacia()) {
        this->pop();
    }
};