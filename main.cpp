#include <iostream>
#include "ds/pila.cpp"
#include "ds/cola.cpp"


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

    return 1;
};
