#include <iostream>
#include "CWDLibrary.h"

/////////////////////////////////////////////////
// GETTERS / SETTERS
/////////////////////////////////////////////////

const char *	CWDLibrary::getName(void) const
{
	return (this->name);
}

/////////////////////////////////////////////////
// METHODS
/////////////////////////////////////////////////

bool	CWDLibrary::load(void)
{
	if (this->handler = LoadLibrary(this->path))
		return (true);
	return (false);
}

Dictionary				CWDLibrary::getDictionary(void)
{
	GET_DICTIONARY	getDict;

	if (!(getDict = (GET_DICTIONARY)GetProcAddress(this->handler, DICTIONARY_GETTER)))
		return (NULL);
	return (getDict());
}

void * CWDLibrary::getClassInstance(void) {
	void *item;
	if (!(item = (void*)GetProcAddress(this->handler, CLASS_INSTANCE_GETTER)))
		return NULL;
	return (item);
}

bool	CWDLibrary::close(void)
{
	return (FreeLibrary(this->handler));
}