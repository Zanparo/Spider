#include <iostream>
#include "DLibrary.h"

#ifdef __linux__
	#include "CUDLibrary.h"
#elif _WIN32
	#include "CWDLibrary.h"
#endif

/////////////////////////////////////////////////////////
// DLFactory
/////////////////////////////////////////////////////////

IDLibrary*		DLFactory::createLibrary(int _id, const char *_name, const char *_path)
{
	IDLibrary	*library;

	#ifdef __linux__
		library = new CUDLibrary(_id, _name, _path);
	#elif _WIN32
		library = new CWDLibrary(_id, _name, _path);
	#endif

	return (library);
}

/////////////////////////////////////////////////////////
// DLHandler
/////////////////////////////////////////////////////////

void	DLHandler::add(IDLibrary *lib)
{
	this->libs.push_back(lib);
}

bool	DLHandler::loadByName(std::string name)
{
	for (std::list<IDLibrary *>::const_iterator lib = this->libs.begin(); lib != libs.end(); ++lib) {
		if (name == (*lib)->getName())
			return ((*lib)->load());
	}
	return (false);
}

Dictionary	DLHandler::getDictionaryByName(std::string name)
{
	for (std::list<IDLibrary *>::const_iterator lib = this->libs.begin(); lib != libs.end(); ++lib) {
		if (name == (*lib)->getName())
			return ((*lib)->getDictionary());
	}
	return (NULL);
}

void * DLHandler::getClassInstanceByName(std::string name) {
	for (std::list<IDLibrary *>::const_iterator lib = this->libs.begin(); lib != libs.end(); ++lib) {
		if (name == (*lib)->getName())
			return ((*lib)->getClassInstance());
	}
	return (NULL);
}

bool	DLHandler::closeList(void)
{
	for (std::list<IDLibrary *>::const_iterator lib = this->libs.begin(); lib != libs.end(); ++lib) {
		(*lib)->close();
	}
	return (true);
}

/////////////////////////////////////////////////////////
// DLManager
/////////////////////////////////////////////////////////

void			DLManager::add(int _id, const char *_name, const char *_path)
{
	IDLibrary	*lib;

	lib = this->factory.createLibrary(_id, _name, _path);
	this->handler.add(lib);
}
