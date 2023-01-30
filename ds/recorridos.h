#pragma once
#define recorridosdefinidos
#include "comun.h"
#ifndef coladefinida
#include "cola.h"
#endif
#ifndef arbolbinariodefinido
#include "arbolBinario.h"
#endif

namespace RECORRIDOS {
    enum TIPOS {
        PREORDEN,
        POSTORDEN,
        INORDEN,
    };

    template <class T>
    COLA<T> recorridoArbolBinario(
        ARBOL_BINARIO<T>,
        TIPOS
    );

    template <class T>
    void preorden(nodoBinario<T>*, COLA<T>*);

    template <class T>
    void postorden(nodoBinario<T>*, COLA<T>*);

    template <class T>
    void inorden(nodoBinario<T>*, COLA<T>*);
};

#include "recorridos/recorridosArbolBinario.cpp"