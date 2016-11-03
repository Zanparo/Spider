#include <iostream>
#include "client.h"
#include "sayHello.h"

/////////////////////////////////////////////////////////////////
//  SETTINGS
/////////////////////////////////////////////////////////////////

clientController::clientController(void) throw(DLibraryException)
{

	//////////////////////////////
	// Load libraries
	//////////////////////////////

	#ifdef __linux__
		this->libraries.add(1, "sayHello", "./libsayHello.so");
		this->libraries.add(2, "network", "./libnetwork.so");
	#elif _WIN32
		this->libraries.add(1, "sayHello", "sayHello.dll");
		this->libraries.add(3, "network", "network.dll");
	#endif

	if (!(this->libraries.handler.loadByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't load module.");
	if (!(this->sayHello = this->libraries.handler.getDictionaryByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't get Dictionary.");

	if (!(this->libraries.handler.loadByName("network")))
		throw DLibraryException("network", "Couldn't load module.");
	if (!(this->network = this->libraries.handler.getDictionaryByName("network")))
		throw DLibraryException("network", "Couldn't get Dictionary.");
}

clientController::~clientController(void)
{
	this->libraries.handler.closeList();
}

/////////////////////////////////////////////////////////////////
//  SCENARIO
/////////////////////////////////////////////////////////////////

int		clientController::mainAction(int ac, char **av) {

	// Dire bonjour
	this->sayHelloAction();

	// Initialiser les sockets
	if (!this->initSocketAction(OPEN_SSL))
	  ; // Ecrire en local

	// Faire pleins de trucs ...
	// ...

	// Quitter
	return (0);
}

void	clientController::sayHelloAction(void) {

  ((_sayHelloFrom)(*this->sayHello)["sayHelloFrom"])("client");

}

bool	clientController::initSocketAction(SOCKET_COM com) {

  this->socket = ((_getSocket)(*this->network)["getSocket"])(com);

  return (this->socket->init());
}
