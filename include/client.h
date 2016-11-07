#pragma warning(disable : 4290)
#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "DataHandler.h"

class	clientController {

	DLManager	libraries;

	// Dictionaries
	Dictionary	sayHello;
	Dictionary	dictDataHandler;

	DataHandler	*dataHandler;

public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);							// Destroy

	int			mainAction(int, char**);
	void		sayHelloAction(void);
	bool		initDataHandlerAction(void);

};

#endif /* !CLIENT_H__ */
