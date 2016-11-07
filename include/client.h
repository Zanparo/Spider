#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "IInfoClient.h"

class	clientController {

	DLManager	libraries;

	// Dictionaries
	Dictionary	sayHello;
	
public:

	clientController(void) throw(DLibraryException);	// Initialise
	~clientController(void);			        // Destroy

	int		mainAction(int, char**);
	void		sayHelloAction(void);

private:
	_I_InfoClient *ifinstance;
};

#endif /* !CLIENT_H__ */
