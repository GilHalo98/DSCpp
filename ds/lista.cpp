#include "comun.h"
#include "estructuras.h"

template <class T>
ESTRUCTURA::LISTA<T>::LISTA(int limiteDatos) {
    // Limite de datos de la estructura.
    this->limiteDatos = limiteDatos;

    // Cantidad de datos actual de la estructura.
    this->cantidadDatos = 0;

    // Puntero inicio de la estructura.
    this->punteroInicio = NULL;

    // Puntero fin de la estructura.
    this->punteroFin = NULL;
};

template <class T>
ESTRUCTURA::LISTA<T>::~LISTA(void) {};

template <class T>
void ESTRUCTURA::LISTA<T>::push(T dato, int index) {
    // Agrega un elemento a la estructura.

    // Si la estructura no esta llena, se pueden agregar
    // datos a esta.
    if(!this->estaLlena()) {
        // Se crea un nuevo nodo.
        nodoSimple<T>* nodoNuevo = new nodoSimple<T>();

        // Se asigna el index y el dato al nodo.
        nodoNuevo->dato = dato;

        // Si la estructura esta vacia.
        if(this->estaVacia()) {
            // El puntero inicio y fin apuntan al nuevo nodo.
            this->punteroInicio = nodoNuevo;
            this->punteroFin = nodoNuevo;


        } else {
            // En caso de que el index se en 0.
            if(index == 0) {
                // Se enlaza el puntero siguiente del nuevo nodo al puntero inicio.
                nodoNuevo->siguiente = this->punteroInicio;

                // El puntero inicio se cambia al nuevo nodo.
                this->punteroInicio = nodoNuevo;

            // En caso de que el index sea en N.
            } else if(index == this->cantidadDatos) {
                // El siguiente del elemento en el puntero fin se enlaza
                // con el nuevo nodo.
                this->punteroFin->siguiente = nodoNuevo;

                // El puntero fin se cambia al nuevo nodo.
                this->punteroFin = nodoNuevo;

            // En caso de que el index sea en 0 < i < n.
            } else {
                // Se instancia un puntero auxiliar que inicie en el puntero inicio.
                nodoSimple<T>* punteroAux = this->punteroInicio;

                // Index relativo a la lista.
                int i = 0;

                // Buscamos el nodo anterior al index en el que queremos hacer push.
                while(i < index - 1) {
                    punteroAux = punteroAux->siguiente;
                    i++;
                }

                // El puntero siguiente del nuevo nodo se enlaza con el puntero
                // siguiente del puntero auxiliar.
                nodoNuevo->siguiente = punteroAux->siguiente;

                // El puntero siguiente del puntero auxiliar se enlaza con el nuevo nodo.
                punteroAux->siguiente = nodoNuevo;
            }
        }

        // Incrementa la cantidad de datos contada.
        this->cantidadDatos++;
    }
};

template <class T>
T ESTRUCTURA::LISTA<T>::pop(int index) {
    // Retira un elemento de la estructura.

    // Si el index es -1, valor por default.
    if(index < 0) {
        // El index que se toma es el del ultimo
        // elemento en la lista.
        index = this->cantidadDatos - 1;

    // Si el index es mayor que N - 1, se retorna un valor nulo.
    } else if(index >= this->cantidadDatos) {
        return (T)NULL;
    }

    // Si la estructura no esta vacia, se pueden remover
    // datos de esta.
    if(!this->estaVacia()) {
        // Instanciamos el puntero del nodo a remover.
        nodoSimple<T>* punteroNodoRemovido;

        // En caso que que el index este ente 1 y N - 1.
        if(index > 0 && index < this->cantidadDatos) {
            // Se instancia un puntero auxiliar y
            // se inicializa en puntero inicio.
            nodoSimple<T>* punteroAux = this->punteroInicio;

            // Se inicializa un conteo de index en 0.
            int i = 0;

            // Movemos el puntero auxiliar una
            // posicion antes que el nodo en index.
            while(i < index - 1) {
                punteroAux = punteroAux->siguiente;
                i++;
            }

            // Inicializamos el puntero nodo removido
            // en el puntero auxiliar siguiente.
            punteroNodoRemovido = punteroAux->siguiente;

            // Enlazamos el puntero auxiliar siguiente al
            // puntero del nodo removido siguiente.
            punteroAux->siguiente = punteroNodoRemovido->siguiente;

            // Si el index es N - 1.
            if(index == this->cantidadDatos - 1) {
                // El puntero fin se establece al puntero auxiliar.
                this->punteroFin = punteroAux;
            }

        // En caso de que el index se encuentre en 0.
        } else {
            // El puntero del nodo removido se declara en
            // el puntero inicio.
            punteroNodoRemovido = this->punteroInicio;

            // Si la cantidad de datos es 1.
            if(this->cantidadDatos == 1) {
                // Los punteros inicio y fin se establecen a NULL.
                this->punteroInicio = NULL;
                this->punteroFin = NULL;

            // Si la cantidad de datos > 1.
            } else {

                // El puntero inicio se establece al
                // puntero siguiente del nodo removido.
                this->punteroInicio = punteroNodoRemovido->siguiente;
            }
        }

        // Recuperamos el dato eliminado.
        T dato = punteroNodoRemovido->dato;

        // Eliminamos el nodo.
        delete punteroNodoRemovido;

        // Decrementamos el contedo de datos.
        this->cantidadDatos--;

        // Retornamos el dato del nodo eliminado.
        return dato;

    } else {
        // si la estructura esta vacia, se retorna
        // NULL.
        return (T)NULL;
    }
};

template <class T>
T ESTRUCTURA::LISTA<T>::operator [] (int index) {
    // Sobrecarga del operador de acceso por indice.

    // Variable que contendra el dato rescatado.
    T dato;

    // Si la estructura no esta vacia.
    if(!this->estaVacia()) {
        if(index >= 0 && index <= this->cantidadDatos - 1) {
            // Si el index se encuentra dentro del
            // rando de los datos en la estructura.

            // Se crea un puntero auxiliar y una
            // variable que almacene el index en el
            // que se encuentra.
            nodoSimple<T>* punteroAux = this->punteroInicio;
            int i = 0;

            // Itera hasta posicionarse en el index
            // deseado.
            while(i < index) {
                punteroAux = punteroAux->siguiente;
                i++;
            }

            // Por ultimo se asigna el dato
            // encontrado a la variable dato.
            dato = punteroAux->dato;
        } else {
            // En caso de solicitar un dato que no
            // existe, se lanza una excepcion.
            throw std::invalid_argument("ERROR DE ACCESO: Index fuera de limites!");
        }

    } else {
        throw std::invalid_argument("ERROR DE ACCESO: Estructura sin elementos!");
    }

    return dato;
};

template <class T>
void ESTRUCTURA::LISTA<T>::debug() {
    // Si la estructura no esta vacia, se imprime
    // su contendio.
    if(!this->estaVacia()) {
        nodoSimple<T>* punteroAux = this->punteroInicio;

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
void ESTRUCTURA::LISTA<T>::dump(void) {
    // Vacia la estructura de datos.
    while(!this->estaVacia()) {
        this->pop();
    }
};

template <class T>
nodoSimple<T>* ESTRUCTURA::LISTA<T>::getPunteroInicio(void) {
    // Retorna el puntero inicio de la estructura.
    return this->punteroInicio;
};

template <class T>
nodoSimple<T>* ESTRUCTURA::LISTA<T>::getPunteroFin(void) {
    // Retorna el puntero fin de la estructura.
    return this->punteroFin;
};