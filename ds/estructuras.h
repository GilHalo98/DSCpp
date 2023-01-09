// Deficnicion de macros.
#pragma once

// Librerias a incluir
#include "comun.h"

namespace ESTRUCTURA {
    class EstructuraBase {
        public:
            // Constructor de la estructura, por default la cantidad
            // de datos maxima no tiene limite.
            EstructuraBase(int=0);

            // Destructor de la estructura.
            ~EstructuraBase(void);

            // Retorna el limite de los datos en la estructura.
            int getLimiteDatos(void);

            // Retorna la cantidad actual de datos en la estructura.
            int getCantidadDatos(void);

            // Indica si la estructura esta vacia.
            bool estaVacia(void);

            // Indica si la estructura esta llena.
            bool estaLlena(void);

        protected:
            // Limite de datos en la estructura.
            int limiteDatos;

            // Cantidad de datos actual en la estructura.
            int cantidadDatos;

        private:
    };

    template <class T>
    class PILA : public EstructuraBase {
        public:
            // Constructor de clase.
            PILA(int=0);

            // Destructor de clase.
            ~PILA(void);

            // Realiza un push a la estructura con el dato de tipo T.
            void push(T);

            // Realiza un pop a la estructura y retorna el dato de tipo
            // T.
            T pop(void);

            // Elimina todos los datos de la estructura.
            void dump(void);

            // Imprime en consola los datos de la estructura.
            void debug(void);

        protected:

        private:
            // Puntero a la parte superior de la estructura.
            nodoSimple<T>* punteroSuperior;
    };

    template <class T>
    class COLA : public EstructuraBase {
        public:
            // Contructor de clase.
            COLA(int=0);

            // Destructor de clase.
            ~COLA(void);

            // Realiza un push en la estructura.
            void push(T);

            // Realiza un pop a la estructura y reporta el dato eliminado.
            T pop(void);

            // Imprime los datos almacenados en la estructura.
            void debug(void);

            // Vacia la estructura.
            void dump(void);

        protected:

        private:
            // Puntero a la parte frontal de la estructura.
            nodoSimple<T>* punteroFrente = NULL;

            // Puntero a la parte tracera de la estructura.
            nodoSimple<T>* punteroCola = NULL;
    };

    template <class T>
    class LISTA : public EstructuraBase {
        public:
            // Constructor de clase de la estructura.
            LISTA(int=0);

            // Destructor de clase de la estructura.
            ~LISTA(void);

            // Agrega un elemento en el index dado.
            void push(T, int=0);

            // Elimina un elemento en el index dado.
            T pop(int=0);

            // Imprime los datos almacenados en la estructura.
            void debug(void);

            // Vacia la estructura.
            void dump(void);

            // Accede a un dato en un index dado con el operador
            // de acceso de arreglos.
            T operator [] (int);

            // Retorna el puntero de inicio de la estructura.
            nodoSimple<T>* getPunteroInicio(void);

            // Retorna el puntero fin de la estructura.
            nodoSimple<T>* getPunteroFin(void);

        protected:

        private:
            // Puntero de inicio de la estructura.
            nodoSimple<T>* punteroInicio;

            // Puntero fin de la estructura.
            nodoSimple<T>* punteroFin;
    };

    template <class T>
    class LISTA_DOBLE : public EstructuraBase {
        public:
            // Constructor de clase.
            LISTA_DOBLE(int=0);

            // Destructor de clase.
            ~LISTA_DOBLE(void);

            // Agrega un elemento en el index dado.
            void push(T, int=0);

            // Elimina un elemento en el index dado.
            T pop(int=0);

            // Imprime los datos almacenados en la estructura.
            void debug(void);

            // Vacia la estructura.
            void dump(void);

            // Accede a un dato en un index dado con el operador
            // de acceso de arreglos.
            T operator [] (int);

            // Retorna el puntero de inicio de la estructura.
            nodoDoble<T>* getPunteroInicio(void);

            // Retorna el puntero fin de la estructura.
            nodoDoble<T>* getPunteroFin(void);

        protected:

        private:
            // Puntero de inicion de la estructura.
            nodoDoble<T>* punteroInicio;

            // Puntero de fin de la estructura.
            nodoDoble<T>* punteroFin;
    };

    template <class T>
    class ARBOL_BINARIO : public EstructuraBase {
        public:
            // Constructor de clase.
            ARBOL_BINARIO(int=0);

            // Destructor de clase.
            ~ARBOL_BINARIO(void);

            // Agrega un elemento a la estructura.
            void push(T);

            // Remueve en orden un dato de la estructura.
            T pop(bool=true);

            // Vacia la estructura.
            void dump(void);

            // Retorna el puntero raiz de la estructura.
            nodoBinario<T>* getPunteroRaiz(void);

        protected:
            // Puntero al elemento raiz de la estructura.
            nodoBinario<T>* punteroRaiz;

        private:
            // Busca una rama de manera recursiva en la que
            // se agregara un elemento.
            nodoBinario<T>* buscarRama(nodoBinario<T>*, nodoBinario<T>*);

            // Indica si un nodo es hoja.
            bool esHoja(nodoBinario<T>*);

            // Busca el elemento mayor de la estructura.
            nodoBinario<T>* buscarMayorElemento(nodoBinario<T>*);

            // Busca el elemento menor de la estructura.
            nodoBinario<T>* buscarMenorElemento(nodoBinario<T>*);
    };
}