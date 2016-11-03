#include "sayHello.h"

/////////////////////////////////////////////////////
// Sources
/////////////////////////////////////////////////////

void	sayHelloFrom(std::string from)
{
	std::cout << "Hello World from " << from << std::endl;
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
		(*dict)["sayHelloFrom"] = &sayHelloFrom;

		return (dict);
	}
}