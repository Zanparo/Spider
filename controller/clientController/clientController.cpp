#include <iostream>
#include "client.h"

/////////////////////////////////////////////////////////////////
//  SETTINGS
/////////////////////////////////////////////////////////////////

clientController::clientController(void) throw(DLibraryException)
{

	//////////////////////////////
	// Load libraries
	//////////////////////////////

	#ifdef __linux__
		this->libraries.add(1, "dataHandler", "./libdataHandler.so");
	#elif _WIN32
		this->storeFolder = "C:\\\\spider\\";
		this->libraries.add(1, "dataHandler", "dataHandler.dll");
	#endif

		this->bytePerFile = 4;
		std::string		err;

	if (!(this->libraries.handler.loadAll(err)))
		throw DLibraryException(err.c_str(), "Couldn't load module.");

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

	this->saveDataAction("Hello World !");
	this->saveDataAction("This is as sentence ;)");
	this->sendLocalDataAction();

	// Faire pleins de trucs ...
	// ...
	system("pause");

	// Quitter
	return (0);
}

bool	clientController::saveDataAction(std::string raw)
{
	this->dataHandler->fileHandler->insertDataToStream(raw);
	//this->dataHandler->fileHandler->showStream();
	return (true);
}

bool			clientController::sendLocalDataAction(void)
{
	std::string	buffer;

	buffer = this->dataHandler->fileHandler->extractDataFromStream(10);
	while (buffer.size())
	{
		// Here we can send buffer to server
		std::cout << "[BUFFER] : " << buffer << std::endl;
		this->dataHandler->fileHandler->removeLocalData(10);
		buffer = this->dataHandler->fileHandler->extractDataFromStream(10);
	}
	return (true);
}

bool					clientController::initDataHandlerAction(void) {

	if (!(this->dataHandler = ((_getDataHandler)(*this->dictDataHandler)["getDataHandler"])()))
		return (false);

	this->dataHandler->fileHandler->initStream(this->storeFolder, this->bytePerFile);
	return (true);
}