template <class T>
void ORDENAMIENTO::bubbleSort(
    LISTA<T>* lista,
    bool ascendente
) {
    // Iniciamos el puntero de los elementos acomodados en nulo.
    nodoSimple<T>* punteroAcomodado = NULL;

    // Tipo de ordenamiento.
    bool orden;

    // Index para el intercambio de datos.
    int indexA;
    int indexB;

    // Mientras que el puntero acomodado sea
    // distinto del puntero inicio.
    while(punteroAcomodado != lista->getPunteroInicio()) {
        // Iniciamos el puntero auxiliar al puntero inicio.
        nodoSimple<T>* punteroAux = lista->getPunteroInicio();

        // Iniciamos el conteo del index en 0.
        int index = 0;

        // Mientras que todavia existan elementos que comparar.
        while(punteroAux->siguiente != punteroAcomodado) {

            // tipo de orden de los datos seleccionada.
            if(ascendente) {
                orden = punteroAux->dato > punteroAux->siguiente->dato;
                indexA = index + 1;
                indexB = index;
            } else {
                orden = punteroAux->dato < punteroAux->siguiente->dato;
                indexA = index;
                indexB = index + 1;
            }

            // Si el dato en puntero auxiliar es mayor que en el elemento
            // siguiente.
            if(orden) {
                // Se intercambian los datos.
                lista->intercambiarDatos(indexA, indexB);
            }

            // Movemos el puntero auxiliar.
            punteroAux = punteroAux->siguiente;

            // Incrementamos el index.
            index++;
        }
        // Movemos el puntero acomodado a la ultima posicion
        // del puntero auxiliar.
        punteroAcomodado = punteroAux;
    }
};

template <class T>
void ORDENAMIENTO::bubbleSort(
    LISTA_DOBLE<T>* lista,
    bool ascendente
) {
    // Iniciamos el puntero de los elementos acomodados en nulo.
    nodoDoble<T>* punteroAcomodado = NULL;

    // Tipo de ordenamiento.
    bool orden;

    // Index para el intercambio de datos.
    int indexA;
    int indexB;

    // Mientras que el puntero acomodado sea
    // distinto del puntero inicio.
    while(punteroAcomodado != lista->getPunteroInicio()) {
        // Iniciamos el puntero auxiliar al puntero inicio.
        nodoDoble<T>* punteroAux = lista->getPunteroInicio();

        // Iniciamos el conteo del index en 0.
        int index = 0;

        // Mientras que todavia existan elementos que comparar.
        while(punteroAux->siguiente != punteroAcomodado) {

            // tipo de orden de los datos seleccionada.
            orden = punteroAux->dato < punteroAux->siguiente->dato;
            if(ascendente) {
                indexA = index + 1;
                indexB = index;
            } else {
                indexA = index;
                indexB = index + 1;
            }

            // Si el dato en puntero auxiliar es mayor que en el elemento
            // siguiente.
            if(orden) {
                // Se intercambian los datos.
                lista->intercambiarDatos(indexA, indexB);
            }

            // Movemos el puntero auxiliar.
            punteroAux = punteroAux->siguiente;

            // Incrementamos el index.
            index++;
        }
        // Movemos el puntero acomodado a la ultima posicion
        // del puntero auxiliar.
        punteroAcomodado = punteroAux;
    }
};