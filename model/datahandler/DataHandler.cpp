#include "DataHandler.h"

/////////////////////////////////////////////////////
// Instanciate DataHandler
/////////////////////////////////////////////////////

IDataHandler		*getDataHandler(void)
{
	IDataHandler	*instance = new DataHandler();

	return (instance);
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
		(*dict)["getDataHandler"] = (void *)&getDataHandler;

		return (dict);
	}
}
