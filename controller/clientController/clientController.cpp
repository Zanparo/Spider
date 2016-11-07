#include <iostream>
#include "client.h"
#include "sayHello.h"
#include "FileHandler.h"

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
		this->libraries.add(1, "dataHandler", "./libdataHandler.so");
	#elif _WIN32
		this->libraries.add(1, "sayHello", "sayHello.dll");
		this->libraries.add(1, "dataHandler", "dataHandler.dll");
	#endif

		std::string		err;

	if (!(this->libraries.handler.loadAll(err)))
		throw DLibraryException(err.c_str(), "Couldn't load module.");

	if (!(this->sayHello = this->libraries.handler.getDictionaryByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't get Dictionary.");

	if (!(this->dictDataHandler = this->libraries.handler.getDictionaryByName("dataHandler")))
		throw DLibraryException("dataHandler", "Couldn't get Dictionary.");
}

clientController::~clientController(void)
{
	this->libraries.handler.closeList();
}

/////////////////////////////////////////////////////////////////
//  SCENARIO
/////////////////////////////////////////////////////////////////

int		clientController::mainAction(int ac, char **av) {

	if (!this->initDataHandlerAction())
		return (1);

	// Dire bonjour
	this->sayHelloAction();

	// Faire pleins de trucs ...
	// ...
	system("pause");

	// Quitter
	return (0);
}

void					clientController::sayHelloAction(void) {

	((_sayHelloFrom)(*this->sayHello)["sayHelloFrom"])("client");

}

bool					clientController::initDataHandlerAction(void) {

	if (!(this->dataHandler = ((_getDataHandler)(*this->dictDataHandler)["getDataHandler"])()))
		return (false);
	return (true);
}