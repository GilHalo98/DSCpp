// Deficnicion de macros.
#pragma once

// Librerias a incluir
#include "comun.h"

namespace ESTRUCTURA {
    template <class T>
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
    class PILA : public EstructuraBase<T> {
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

        private:
            // Puntero a la parte superior de la estructura.
            nodoSimple<T>* punteroSuperior;

        protected:
    };

    template <class T>
    class COLA : public EstructuraBase<T> {
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

        private:
            // Puntero a la parte frontal de la estructura.
            nodoSimple<T>* punteroFrente = NULL;

            // Puntero a la parte tracera de la estructura.
            nodoSimple<T>* punteroCola = NULL;

        protected:
    };

}
