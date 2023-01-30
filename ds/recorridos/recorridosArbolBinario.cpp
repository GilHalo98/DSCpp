template <class T>
COLA<T> RECORRIDOS::recorridoArbolBinario(
    ARBOL_BINARIO<T> arbolBinario,
    RECORRIDOS::TIPOS tipoRecorrido
) {
    // Realiza los recorridos a los arboles binarios, los tipos
    // aceptados son; inorden, postorden, preorden.
    
    // Declaramos la cola del recorrido.
    COLA<T> colaRecorrido = COLA<T>(
        arbolBinario.getCantidadDatos()
    );

    // Switch/Case de los distintos tipos de recorridos validos.
    switch(tipoRecorrido) {
        case RECORRIDOS::TIPOS::PREORDEN:
            RECORRIDOS::preorden(
                arbolBinario.getPunteroRaiz(),
                &colaRecorrido
            );
            break;

        case RECORRIDOS::TIPOS::POSTORDEN:
            RECORRIDOS::postorden(
                arbolBinario.getPunteroRaiz(),
                &colaRecorrido
            );
            break;

        case RECORRIDOS::TIPOS::INORDEN:
            RECORRIDOS::inorden(
                arbolBinario.getPunteroRaiz(),
                &colaRecorrido
            );
            break;

        default:
            throw std::invalid_argument(
                "ERROR DE OPCION: Tipo de recorrido invalido!"
            );
            break;
    } 

    return colaRecorrido;
};

template <class T>
void RECORRIDOS::preorden(
    nodoBinario<T>* punteroAux,
    COLA<T>* colaRecorrido
) {
    // Recorrido preorden del arbol binario.
    if(punteroAux != NULL) {
        colaRecorrido->push(punteroAux->dato);
        RECORRIDOS::preorden(punteroAux->hijoIzquierda, colaRecorrido);
        RECORRIDOS::preorden(punteroAux->hijoDerecha, colaRecorrido);
    }
};

template <class T>
void RECORRIDOS::postorden(
    nodoBinario<T>* punteroAux,
    COLA<T>* colaRecorrido
) {
    // Recorrido postorden del arbol binario.
    if(punteroAux != NULL) {
        RECORRIDOS::postorden(punteroAux->hijoIzquierda, colaRecorrido);
        RECORRIDOS::postorden(punteroAux->hijoDerecha, colaRecorrido);
        colaRecorrido->push(punteroAux->dato);
    }
};

template <class T>
void RECORRIDOS::inorden(
    nodoBinario<T>* punteroAux,
    COLA<T>* colaRecorrido
) {
    // Recorrido inorden del arbol binario.
    if(punteroAux != NULL) {
        RECORRIDOS::inorden(punteroAux->hijoIzquierda, colaRecorrido);
        colaRecorrido->push(punteroAux->dato);
        RECORRIDOS::inorden(punteroAux->hijoDerecha, colaRecorrido);
    }
};
