#include <iostream>
#include "ds/DS.h"
#include "ds/pila.cpp"

int main(void) {
	std::cout<<"Pila"<<std::endl;
	ESTRUCTURAS::PILA<int> pila = ESTRUCTURAS::PILA<int>(10);
	pila.push(3);
	pila.push(5);
	pila.push(9);

	pila.debug();
	int dato = pila.pop();

	// Deberia de ser 9
	std::cout<<dato<<std::endl;

	pila.debug();

	pila.dump();
	pila.debug();

	return 1;
}
