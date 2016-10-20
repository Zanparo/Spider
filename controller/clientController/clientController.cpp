#include <iostream>
#include "client.h"

int		clientController::mainAction(int ac, char *av[]) {
	
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

void	clientController::sayHelloAction(void) const {
	// Normalement c'est la vue qui fais ça (YOLO)
	std::cout << "client: Hello World !" << std::endl;
}