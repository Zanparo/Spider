#pragma warning(disable : 4290)
#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "sayHello.h"
# include "DataHandler.h"

class	clientController {

	DLManager		libraries;

	// Dictionaries
	Dictionary		sayHello;
	Dictionary		dictDataHandler;

	std::string		storeFolder;
	int				bytePerFile;
	IDataHandler*	dataHandler;


public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);							// Destroy

	int			mainAction(int, char**);
	bool		initDataHandlerAction(void);
	bool		saveDataAction(std::string);
	bool		sendLocalDataAction(void);
};

#endif /* !CLIENT_H__ */
