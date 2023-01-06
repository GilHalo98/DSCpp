#pragma once
#include "nodos.cpp"

namespace ESTRUCTURAS {
	template <class T>
	class PILA {
		public:
			PILA(int=0);
			~PILA(void);

			// Indica si la pila esta llena.
			bool estaLlena();

			// Indica si la pila esta vacia.
			bool estaVacia();

			// Agrega un elemento a la pila.
			bool push(T);

			// Remueve un elemento de la pila.
			T pop();

			// Vacia la pila.
			bool dump();

			// Retorna la cantidad de elementos en la pila.
			int getCantidadDatos();

			// Retorna la capacidad de la pila.
			int getCapacidad();

			// Muestra el contenido de la pila.
			void debug();

		private:

		protected:
			// Indica la cantidad maxima de elementos en la pila.
			int capacidadDatos;

			// Indica la cantidad actual de elemetos en la pila.
			int cantidadDatos;

			// Puntero inicio de la pila.
			NodoSimple<T>* punteroSuperior;
	};
}
