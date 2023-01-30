#pragma once
#include "comun.h"
#ifndef listadefinida
#include "lista.h"
#endif
#ifndef listadobledefinida
#include "listaDoble.h"
#endif
#ifndef arbolbinariodefinido
#include "arbolBinario.h"
#endif

namespace ORDENAMIENTO {
    // Bubblesort para listas.
    template <class T>
    void bubbleSort(LISTA<T>*, bool=true);

    // Bubblesort para listas doble.
    template <class T>
    void bubbleSort(LISTA_DOBLE<T>*, bool=true);

    // Binary Tree sort para listas.
    template <class T>
    void binaryTreeSort(LISTA<T>*, bool=true);

    // Binary Tree sort para listas doble.
    template <class T>
    void binaryTreeSort(LISTA_DOBLE<T>*, bool=true);
};
#include "ordenamiento/binarytreesort.cpp"
#include "ordenamiento/bubblesort.cpp"