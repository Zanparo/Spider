#include <iostream>
#include "DLibrary.h"
#include "WorkQueue.h"

/////////////////////////////////////////////////////
// getAWorkQueue
/////////////////////////////////////////////////////

IWorkQueue			*getAWorkQueue(void)
{
	IWorkQueue		*workQueue;

	workQueue = new WorkQueue();
	return (workQueue);
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
		(*dict)["getAWorkQueue"] = (void *)&getAWorkQueue;

		return (dict);
	}
}
