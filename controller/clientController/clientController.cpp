#include <iostream>
#include "client.h"
#include "sayHello.h"
#include "IInfoClient.h"

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
	#elif _WIN32
		this->libraries.add(1, "sayHello", "sayHello.dll");
		this->libraries.add(2, "infoClient", "InfoClient.dll");
	#endif

	if (!(this->libraries.handler.loadByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't load module.");
	if (!(this->sayHello = this->libraries.handler.getDictionaryByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't get Dictionary.");

	if (!(this->libraries.handler.loadByName("infoClient")))
		throw DLibraryException("infoClient", "Couldn't load module.");
	Sleep(1);
	if (!(this->infoClient = this->libraries.handler.getDictionaryByName("infoClient")))
		throw DLibraryException("infoClient", "Couldn't get ClassInstance");
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
	ifinstance = ((_getInstance)(*this->infoClient)["getInstance"])();
	// Faire pleins de trucs ...
	// ...

	// Quitter
	return (0);
}

void					clientController::sayHelloAction(void) {

	((_sayHelloFrom)(*this->sayHello)["sayHelloFrom"])("client");

}
