template <class T>
int binarySearch(LISTA<T>* lista, T datoBusqueda) {
    // Busqueda binaria de un elemetno en la lista.

    // Primero ordenamos la lista.
    ORDENAMIENTO::bubbleSort(lista);

    // Calculamos el index del centro.
    int indexAux = round((float) lista->getCantidadDatos() / 2);

    // Buscamos un puntero al elemento en el centro de la lista.
    nodoSimple<T>* punteroAux = lista->getPunteroElemento(indexAux);

    // Criterio de parada del algoritmo.
    int iteracionesEsperadas = indexAux;

    // Realizamos la busqueda binaria.
    int i = 0;

    // Mientras que la cantida de iteraciones sea menor que la cantidad
    // de iteraciones esperadas (iteraciones esperadas = n / 2)
    while(i < iteracionesEsperadas) {

        // Si el dato es el buscado, retorna el index.
        if(datoBusqueda == punteroAux->dato) {
            return indexAux;

        } else {
            // Si el dato buscado es mayor que el del pivote.
            if(datoBusqueda > punteroAux->dato) {
                // Movemos el index hacia la derecha.
                indexAux += round(
                    (float) indexAux / 2
                );

            // Si es menor.
            } else {
                // Movemos el index a la izquierda.
                indexAux -= round(
                    (float) indexAux / 2
                );
            }

            // Buscamos el nuevo pivote.
            punteroAux = lista->getPunteroElemento(indexAux);
        }
    }

    // Si no se encuentra el dato, retorna -1.
    return -1;
};

template <class T>
int binarySearch(LISTA_DOBLE<T>* lista, T datoBusqueda) {
    // Busqueda binaria de un elemetno en la lista.

    // Primero ordenamos la lista.
    ORDENAMIENTO::bubbleSort(lista);

    // Calculamos el index del centro.
    int indexAux = round((float) lista->getCantidadDatos() / 2);

    // Buscamos un puntero al elemento en el centro de la lista.
    nodoDoble<T>* punteroAux = lista->getPunteroElemento(indexAux);

    // Criterio de parada del algoritmo.
    int iteracionesEsperadas = indexAux;

    // Realizamos la busqueda binaria.
    int i = 0;

    // Mientras que la cantida de iteraciones sea menor que la cantidad
    // de iteraciones esperadas (iteraciones esperadas = n / 2)
    while(i < iteracionesEsperadas) {

        // Si el dato es el buscado, retorna el index.
        if(datoBusqueda == punteroAux->dato) {
            return indexAux;

        } else {
            // Si el dato buscado es mayor que el del pivote.
            if(datoBusqueda > punteroAux->dato) {
                // Movemos el index hacia la derecha.
                indexAux += round(
                    (float) indexAux / 2
                );

            // Si es menor.
            } else {
                // Movemos el index a la izquierda.
                indexAux -= round(
                    (float) indexAux / 2
                );
            }

            // Buscamos el nuevo pivote.
            punteroAux = lista->getPunteroElemento(indexAux);
        }
    }

    // Si no se encuentra el dato, retorna -1.
    return -1;
};