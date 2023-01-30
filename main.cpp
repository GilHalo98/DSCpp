#include <iostream>
#include "ds/pila.h"
#include "ds/cola.h"
#include "ds/lista.h"
#include "ds/listaDoble.h"
#include "ds/arbolBinario.h"
#include "ds/ordenamiento.h"
#include "ds/busqueda.h"
#include "ds/recorridos.h"

int main() {
    int i;

    std::cout<<"Pila"<<std::endl;
    PILA<int> pila = PILA<int>(10);

    i = 0;
    while(i < pila.getLimiteDatos()) {
        pila.push(i);
        i++;
    }

    pila.debug();

    std::cout<<"Vaciando la pila"<<std::endl;
    while(!pila.estaVacia()) {
        std::cout<<pila.pop()<<", ";
    }
    std::cout<<std::endl;

    /*----------------------------------------------------------------*/
    std::cout<<std::endl;

    std::cout<<"Cola"<<std::endl;
    COLA<int> cola = COLA<int>(10);

    i = 0;
    while(i < cola.getLimiteDatos()) {
        cola.push(0 + (rand() % 200));
        i++;
    }

    cola.debug();

    std::cout<<"Vaciando la cola"<<std::endl;
    while(!cola.estaVacia()) {
        std::cout<<cola.pop()<<", ";
    }
    std::cout<<std::endl;

    /*----------------------------------------------------------------*/
    std::cout<<std::endl;

    std::cout<<"Lista"<<std::endl;
    LISTA<int> lista = LISTA<int>(10);

    i = 0;
    while(i < lista.getLimiteDatos()) {
        lista.push(0 + (rand() % 200));
        i++;
    }

    lista.debug();

    std::cout<<"Ordenamientos de listas"<<std::endl;
    ORDENAMIENTO::bubbleSort(&lista);
    lista.debug();

    std::cout<<"Busqueda binaria en listas"<<std::endl;
    int index = binarySearch(&lista, 161);
    if(index == -1) {
        std::cout<<"Elemento no encontrado"<<std::endl;
    } else {
        std::cout<<"Elemento buscado: "<<161<<" encontrado en index "<<index;
        std::cout<<" dato en index: "<<lista[index]<<std::endl;
    }

    std::cout<<"Vaciando la lista"<<std::endl;
    while(!lista.estaVacia()) {
        std::cout<<lista.pop()<<", ";
    }
    std::cout<<std::endl;

    /*----------------------------------------------------------------*/
    std::cout<<std::endl;

/*----------------------------------------------------------------*/
    std::cout<<std::endl;

    std::cout<<"Lista Doble"<<std::endl;
    LISTA_DOBLE<int> listaDoble = LISTA_DOBLE<int>(10);

    i = 0;
    while(i < listaDoble.getLimiteDatos()) {
        listaDoble.push(0 + (rand() % 200));
        i++;
    }

    listaDoble.debug();

    std::cout<<"Vaciando la lista doble"<<std::endl;
    while(!listaDoble.estaVacia()) {
        std::cout<<listaDoble.pop()<<", ";
    }
    std::cout<<std::endl;

    /*----------------------------------------------------------------*/
    std::cout<<std::endl;

    std::cout<<"Arbol Binario"<<std::endl;
    ARBOL_BINARIO<int> arbolBinario = ARBOL_BINARIO<int>(10);

    i = 0;
    while(i < arbolBinario.getLimiteDatos()) {
        arbolBinario.push(0 + (rand() % 200));
        i++;
    }

    std::cout<<"Recorridos de Arbol Binario"<<std::endl;
    COLA<int> colaRecorrido = RECORRIDOS::recorridoArbolBinario(
        arbolBinario,
        RECORRIDOS::TIPOS::INORDEN
    );
    colaRecorrido.debug();

    std::cout<<"Vaciando el arbol binario"<<std::endl;
    while(!arbolBinario.estaVacia()) {
        std::cout<<arbolBinario.pop()<<", ";
    }
    std::cout<<std::endl;

    return 1;
};
