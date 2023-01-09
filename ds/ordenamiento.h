// Deficnicion de macros.
#pragma once

// Librerias a incluir
#include "comun.h"

namespace ORDENAMIENTO {
    // Bubblesort para listas.
    template <class T>
    void bubbleSort(ESTRUCTURA::LISTA<T>*, bool=true);

    // Bubblesort para listas doble.
    template <class T>
    void bubbleSort(ESTRUCTURA::LISTA_DOBLE<T>*, bool=true);

    // Binary Tree sort para listas.
    template <class T>
    void binaryTreeSort(ESTRUCTURA::LISTA<T>*, bool=true);

    // Binary Tree sort para listas doble.
    template <class T>
    void binaryTreeSort(ESTRUCTURA::LISTA_DOBLE<T>*, bool=true);
};