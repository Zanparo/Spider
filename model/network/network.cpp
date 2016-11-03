#include <iostream>
#include "network.h"

///////////////////////////////////////////////////
// OPEN SSL
///////////////////////////////////////////////////

bool	OpenSSL::init(void)
{
  std::cout << "Init socket : mode SSL" << std::endl;
  return (true);
}


///////////////////////////////////////////////////
// INSTANTIATE
///////////////////////////////////////////////////

ISocket		*getSocket(SOCKET_COM com)
{
  ISocket       *sock;

  switch (com)
    {
    case OPEN_SSL:
      sock = new OpenSSL;
      break;
    }
  return (sock);
}

/////////////////////////////////////////////////////
// Get Dictionary
/////////////////////////////////////////////////////

extern "C" {
	#ifdef __linux__
	Dictionary	getDictionary(void)
	#elif _WIN32
	__declspec(dllexport) Dictionary	__cdecl getDictionary(void)
	#endif
	{
		Dictionary	dict = new std::map<std::string, void *>;

		// List every usefull functions out there
		(*dict)["getSocket"] = (void *)&getSocket;

		return (dict);
	}
}
