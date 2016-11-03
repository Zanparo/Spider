#ifndef NETWORK_H__
# define NETWORK_H__

# include "DLDictionary.h"

class	ISocket
{
public:
  virtual bool	init(void) = 0;
  //virtual bool	connect(void) = 0;
  //virtual bool	sendData(void) = 0;
};

class	OpenSSL : public ISocket
{
public:
  bool		init(void);
};


//
// SPIDER DYNAMIC LIBRARY STANDARDS
//
// Functions type MUST be defined as the name of the function preceded by "_"
//

enum	SOCKET_COM {
  OPEN_SSL = 0
};

typedef ISocket*	(* _getSocket)(SOCKET_COM);

#endif /* !NETWORK_H__ */
