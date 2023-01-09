#include "comun.h"
#include "estructuras.h"

template <class T>
ESTRUCTURA::ARBOL_BINARIO<T>::ARBOL_BINARIO(int limiteDatos) {
    // Limite de datos en la estructura.
    this->limiteDatos = limiteDatos;

    // Cantida de datos en la estructura.
    this->cantidadDatos = 0;

    // Puntero al elemento raiz.
    this->punteroRaiz = NULL;
};

template <class T>
ESTRUCTURA::ARBOL_BINARIO<T>::~ARBOL_BINARIO(void) {};

template <class T>
void ESTRUCTURA::ARBOL_BINARIO<T>::push(T dato) {
    // La funcion permite agregar nodos a la estructura.
    if(!this->estaLlena()) {
        // Se crea un nuevo nodo.
        nodoBinario<T>* nodoNuevo = new nodoBinario<T>();

        // Se asigna el index y el dato al nodo.
        nodoNuevo->dato = dato;

        if(!this->estaVacia()) {
            // Se crea un puntero auxiliar para agregar nodos.
            nodoBinario<T>* punteroAux = this->punteroRaiz;

            // Se busca la rama a la cual se ingesara el nuevo nodo.
            punteroAux = this->buscarRama(punteroAux, nodoNuevo);

            if(nodoNuevo->dato < punteroAux->dato) {
                // Busca una hoja a la Izquierda.
                punteroAux->hijoIzquierda = nodoNuevo;
            } else {
                // Busca una hoja a la Derecha.
                punteroAux->hijoDerecha = nodoNuevo;
            }

            // Se actualiza el puntero padre del nuevo nodo.
            nodoNuevo->nodoPadre = punteroAux;
        } else {
            this->punteroRaiz = nodoNuevo;
        }

        this->cantidadDatos++;
    }
};

template <class T>
nodoBinario<T>* ESTRUCTURA::ARBOL_BINARIO<T>::buscarRama(
    nodoBinario<T>* punteroAux,
    nodoBinario<T>* nodoNuevo
) {
    // Busca la raiz en donde se agregara el nodo.

    // Si el nodo es una hoja, retorna el puntero.
    if(this->esHoja(punteroAux)) {
        return punteroAux;

    // Si no es hoja.
    } else {
        // Si el dato en el nodo es mayor que el nuevo dato.
        if(nodoNuevo->dato < punteroAux->dato) {
            // Si el hijo izquerda esta ocupado.
            if(punteroAux->hijoIzquierda != NULL) {
                // Recorremos hacia la izquierda.
                return buscarRama(punteroAux->hijoIzquierda, nodoNuevo);
            }

        // Si es menor.
        } else {
            // Si el hijo derecha esta ocupado.
            if(punteroAux->hijoDerecha != NULL) {
                // Recorremos a la derecha.
                return buscarRama(punteroAux->hijoDerecha, nodoNuevo);
            }
        }

        // Retornamos el puntero.
        return punteroAux;
    }
};

template <class T>
bool ESTRUCTURA::ARBOL_BINARIO<T>::esHoja(nodoBinario<T>* punteroAux) {
    // Indica si un nodo es hoja.
    if(
        punteroAux->hijoIzquierda == NULL
        && punteroAux->hijoDerecha == NULL
    ) {
        return true;
    }

    return false;
};

template <class T>
T ESTRUCTURA::ARBOL_BINARIO<T>::pop(bool eliminar_mayor) {
    if(!this->estaVacia()) {
        // Permite eliminar datos similar a una estructura de datos lineal
        // por default el orden de eliminacion es decendente.

        // Instanciamos el puntero al nodo a remover.
        nodoBinario<T>* punteroNodoRemovido = this->punteroRaiz;

        // Movemos el puntero del nodo removido al elemento a eliminar.
        if(eliminar_mayor == true) {
            punteroNodoRemovido = this->buscarMayorElemento(
                punteroNodoRemovido
            );
        } else {
            punteroNodoRemovido = this->buscarMenorElemento(
                punteroNodoRemovido
            );
        }

        // Cuando unicamente exista un elemento.
        if(this->cantidadDatos == 1) {
            // Establecemos la raiz como nulo.
            this->punteroRaiz = NULL;
        } else {
            // Puntero padre del nodo removido.
            nodoBinario<T>* punteroPadre = punteroNodoRemovido->nodoPadre;

            // Si el nodo es una hoja.
            if(this->esHoja(punteroNodoRemovido)) {
                // Desconectamos el nodo padre del nodo hijo.
                if(punteroNodoRemovido->dato < punteroPadre->dato) {
                    punteroPadre->hijoIzquierda = NULL;
                } else {
                    punteroPadre->hijoDerecha = NULL;
                }
                
            // En caso de no ser una hoja.
            } else {
                if(punteroNodoRemovido == this->punteroRaiz) {
                    if(punteroNodoRemovido->hijoIzquierda != NULL) {
                        this->punteroRaiz = this->punteroRaiz->hijoIzquierda;
                    } else {
                        this->punteroRaiz = this->punteroRaiz->hijoDerecha;
                    }
                    this->punteroRaiz->nodoPadre = NULL;

                } else {
                    // Reacomodamos la rama del nodo eliminado.
                    if(punteroNodoRemovido->dato < punteroPadre->dato) {
                        punteroPadre->hijoIzquierda = punteroNodoRemovido->hijoDerecha;
                        punteroNodoRemovido->hijoDerecha->nodoPadre = punteroPadre;
                    } else {
                        punteroPadre->hijoDerecha = punteroNodoRemovido->hijoIzquierda;
                        punteroNodoRemovido->hijoIzquierda->nodoPadre = punteroPadre;
                    }
                }
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
        return (T) NULL;
    }
};

template <class T>
nodoBinario<T>* ESTRUCTURA::ARBOL_BINARIO<T>::buscarMenorElemento(
    nodoBinario<T>* punteroAux
) {
    // Busca el elemento con menor valor en el arbol binario.

    // Recorrido inorden del arbol binario.
    if(punteroAux->hijoIzquierda != NULL) {
        return buscarMenorElemento(punteroAux->hijoIzquierda);
    } else {
        return punteroAux;
    }
};

template <class T>
nodoBinario<T>* ESTRUCTURA::ARBOL_BINARIO<T>::buscarMayorElemento(
    nodoBinario<T>* punteroAux
) {
    // Busca el elemento con mayor valor en el arbol binario.

    // Recorrido inorden del arbol binario.
    if(punteroAux->hijoDerecha != NULL) {
        return buscarMayorElemento(punteroAux->hijoDerecha);
    } else {
        return punteroAux;
    }
};

template <class T>
nodoBinario<T>* ESTRUCTURA::ARBOL_BINARIO<T>::getPunteroRaiz(void) {
    // Retorna el puntero raiz de la estructura.
    return this->punteroRaiz;
};