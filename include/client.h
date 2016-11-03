#ifndef CLIENT_H__
# define CLIENT_H__

# include "DLibrary.h"
# include "network.h"

class	clientController {

  DLManager	libraries;

  // Dictionaries
  Dictionary	sayHello;
  Dictionary	network;

  // Network
  ISocket	*socket;

public:

  clientController(void) throw(DLibraryException);	// Initialise
  ~clientController(void);			        // Destroy

  int		mainAction(int, char**);
  void		sayHelloAction(void);
  bool		initSocketAction(SOCKET_COM);

};

#endif /* !CLIENT_H__ */
