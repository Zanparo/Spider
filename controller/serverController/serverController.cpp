#include <iostream>
#include "server.h"

int		serverController::mainAction(int ac, char *av[]) {
	
	/////////////////////////////////////////////////////////////////
	//  SCENARIO
	/////////////////////////////////////////////////////////////////
	
	// Dire bonjour
	this->sayHelloAction();
	
	// Boucler
	while (1)
		;
	
	return (0);
}

void	serverController::sayHelloAction(void) const {
	// Normalement c'est la vue qui fais ça (YOLO)
	std::cout << "server: Hello World !" << std::endl;
}