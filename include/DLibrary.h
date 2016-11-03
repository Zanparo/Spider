#ifndef DLIBRARY_H__
# define DLIBRARY_H__

# include <list>
# include "DLDictionary.h"

////////////////////////////////////////////////////////////////
// IDLibrary
////////////////////////////////////////////////////////////////

class IDLibrary {

public:

	virtual const char			*getName(void) const = 0;

	virtual bool				load(void) = 0;
	virtual bool				close(void) = 0;
	virtual Dictionary			getDictionary(void) = 0;
};


////////////////////////////////////////////////////////////////
// ADLibrary
////////////////////////////////////////////////////////////////

class ADLibrary {
public:
	int			id;
	const char	*name;
	const char	*path;

	ADLibrary(int _id, const char *_name, const char *_path) :
		id(_id), name(_name), path(_path) {}
};


////////////////////////////////////////////////////////////////
// DLFactory
////////////////////////////////////////////////////////////////

class DLFactory {
public:
	IDLibrary	*createLibrary(int, const char *, const char *);
};


////////////////////////////////////////////////////////////////
// DLHandler
////////////////////////////////////////////////////////////////

class DLHandler {
	std::list<IDLibrary *>	libs;

public:
	void		add(IDLibrary *);

	// LOAD
	bool		loadByName(std::string);

	// GET DICTIONNARY
	Dictionary	getDictionaryByName(std::string);

	// CLOSE
	bool		closeList(void);
};


////////////////////////////////////////////////////////////////
// DLManager
////////////////////////////////////////////////////////////////

class DLManager {
	DLFactory	factory;
	
public:
	DLHandler	handler;

	void		add(int, const char *, const char *);
};

////////////////////////////////////////////////////////////////
// Exception
////////////////////////////////////////////////////////////////

class DLibraryException : public std::exception
{
protected:

	std::string		message;

public:

	explicit DLibraryException(const char* name, const char* error) {
		message = std::string("######################################\n");
		message += std::string("##  Error on library : ");
		message += std::string(name);
		message += std::string("\n######################################\n");
		message += std::string(error);
	}

	virtual ~DLibraryException() throw () {}

	virtual const char* what() const throw () {
		return message.c_str();
	}
};

#endif /* !DLIBRARY_H__ */