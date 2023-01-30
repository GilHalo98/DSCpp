// Binary Tree sort para listas.
template <class T>
void ORDENAMIENTO::binaryTreeSort(
    LISTA<T>* lista,
    bool ascendente
) {
    // Instanciamos el arbol auxiliar.
    ARBOL_BINARIO<int> arbol = ARBOL_BINARIO<int>(
        lista->getCantidadDatos()
    );

    // Mientras que la lista tenga elementos, los removemos y
    // los agregamos al arbol.
    T dato;
    while(!lista->estaVacia()) {
        dato = lista->pop();
        arbol.push(dato);
    }

    // Mientras el arbol tenga elementos, los removemos en orden y
    // los agregamos a la lista.
    while(!arbol.estaVacia()) {
        dato = arbol.pop(ascendente);
        lista->push(dato);
    }

    delete arbol;
};

// Binary Tree sort para listas doble.
template <class T>
void ORDENAMIENTO::binaryTreeSort(
    LISTA_DOBLE<T>* lista,
    bool ascendente
) {
    // Instanciamos el arbol auxiliar.
    ARBOL_BINARIO<int> arbol = ARBOL_BINARIO<int>(
        lista->getCantidadDatos()
    );

    // Mientras que la lista tenga elementos, los removemos y
    // los agregamos al arbol.
    T dato;
    while(!lista.estaVacia()) {
        dato = lista->pop();
        arbol.push(dato);
    }

    // Mientras el arbol tenga elementos, los removemos en orden y
    // los agregamos a la lista.
    while(!arbol.estaVacia()) {
        dato = arbol.pop(ascendente);
        lista->push(dato);
    }

    delete arbol;
};