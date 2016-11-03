#include <iostream>
#include <dlfcn.h>
#include "CUDLibrary.h"

/////////////////////////////////////////////////
// GETTERS / SETTERS
/////////////////////////////////////////////////

const char *	CUDLibrary::getName(void) const
{
  return (this->name);
}

/////////////////////////////////////////////////
// METHODS
/////////////////////////////////////////////////

bool	CUDLibrary::load(void)
{
  if (this->handler = dlopen(this->path, RTLD_LAZY))
    return (true);
  return (false);
}

Dictionary				CUDLibrary::getDictionary(void)
{
  GET_DICTIONARY	getDict;

  if (!(getDict = (GET_DICTIONARY)dlsym(this->handler, DICTIONARY_GETTER)))
    return (NULL);
  return (getDict());
}

bool	CUDLibrary::close(void)
{
  return (dlclose(this->handler));
}
