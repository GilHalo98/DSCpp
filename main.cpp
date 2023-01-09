#include <iostream>
#include "ds/pila.cpp"
#include "ds/cola.cpp"
#include "ds/lista.cpp"
#include "ds/listaDoble.cpp"
#include "ds/arbolBinario.cpp"


int main() {
    int i;

    std::cout<<"Pila"<<std::endl;
    ESTRUCTURA::PILA<int> pila = ESTRUCTURA::PILA<int>(10);

    i = 0;
    while(i < pila.getLimiteDatos()) {
        pila.push(i);
        i++;
    }

    pila.debug();

    while(!pila.estaVacia()) {
        std::cout<<pila.pop()<<", ";
    }
    std::cout<<std::endl;

    std::cout<<"Cola"<<std::endl;
    ESTRUCTURA::COLA<int> cola = ESTRUCTURA::COLA<int>(10);

    i = 0;
    while(i < cola.getLimiteDatos()) {
        cola.push(i);
        i++;
    }

    cola.debug();

    while(!cola.estaVacia()) {
        std::cout<<cola.pop()<<", ";
    }
    std::cout<<std::endl;

    std::cout<<"Lista"<<std::endl;
    ESTRUCTURA::LISTA<int> lista = ESTRUCTURA::LISTA<int>(10);

    i = 0;
    while(i < lista.getLimiteDatos()) {
        lista.push(i);
        i++;
    }

    lista.debug();

    while(!lista.estaVacia()) {
        std::cout<<lista.pop()<<", ";
    }
    std::cout<<std::endl;

    std::cout<<"Lista Doble"<<std::endl;
    ESTRUCTURA::LISTA_DOBLE<int> listaDoble = ESTRUCTURA::LISTA_DOBLE<int>(10);

    i = 0;
    while(i < listaDoble.getLimiteDatos()) {
        listaDoble.push(i);
        i++;
    }

    listaDoble.debug();

    while(!listaDoble.estaVacia()) {
        std::cout<<listaDoble.pop()<<", ";
    }
    std::cout<<std::endl;

    std::cout<<"Arbol Binario"<<std::endl;
    ESTRUCTURA::ARBOL_BINARIO<int> arbolBinario = ESTRUCTURA::ARBOL_BINARIO<int>(10);

    i = 0;
    while(i < arbolBinario.getLimiteDatos()) {
        arbolBinario.push(i);
        i++;
    }

    while(!arbolBinario.estaVacia()) {
        std::cout<<arbolBinario.pop()<<", ";
    }
    std::cout<<std::endl;

    return 1;
};
