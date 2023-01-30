#pragma once
#include "comun.h"
#ifndef listadefinida
#include "lista.h"
#endif
#ifndef listadobledefinida
#include "listaDoble.h"
#endif

namespace BUSQUEDA {
    template <class T>
    int binarySearch(LISTA<T>*, T);

    template <class T>
    int binarySearch(LISTA_DOBLE<T>*, T);
};
#include "busqueda\binarysearch.cpp"