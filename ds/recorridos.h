// Deficnicion de macros.
#pragma once

// Librerias a incluir
#include "comun.h"

namespace RECORRIDOS {
    enum TIPOS {
        PREORDEN,
        POSTORDEN,
        INORDEN,
    };

    template <class T>
    ESTRUCTURA::COLA<T> recorridoArbolBinario(
        ESTRUCTURA::ARBOL_BINARIO<T>,
        TIPOS
    );

    template <class T>
    void preorden(nodoBinario<T>*, ESTRUCTURA::COLA<T>*);

    template <class T>
    void postorden(nodoBinario<T>*, ESTRUCTURA::COLA<T>*);

    template <class T>
    void inorden(nodoBinario<T>*, ESTRUCTURA::COLA<T>*);
};