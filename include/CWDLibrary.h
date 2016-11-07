#ifndef CWDLIBRARY_H__
# define CWDLIBRARY_H__

# include <Windows.h>
# include "DLibrary.h"

#define CLASS_INSTANCE_GETTER "getInstance()"

class CWDLibrary : public IDLibrary, private ADLibrary {

	HMODULE			handler;

public:

	CWDLibrary(int _id, const char *_name, const char *_path) :
		ADLibrary(_id, _name, _path) {}

	const char			*getName(void) const;

	bool				load(void);
	bool				close(void);
	Dictionary			getDictionary(void);
	void*				getClassInstance(void);
};

#endif /* !CWDLIBRARY_H__ */
