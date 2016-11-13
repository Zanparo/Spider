#ifndef NETWORKDLL_H__
# define NETWORKDLL_H__

//# ifdef __linux__ 
// Silence is golden
//# elif _WIN32
//#  include <windows.h>
//# endif
# include					<iostream>
# include					<string>
# include					"DLDictionary.h"
# include					"serverManager.h"
# include					"clientManager.h"
# include					"INetwork.h"

//Windows version of destination
#define						_WIN32_WINNT 0x06030000

enum state {
	SERVER,
	CLIENT
};

//
// SPIDER DYNAMIC LIBRARY STANDARDS
//
// Functions type MUST be defined as the name of the function preceded by "_"
//

typedef			INetwork *(*_instanciate)(int);

#endif /* !NETWORKDLL_H__ */