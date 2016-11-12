#ifndef CWDLIBRARY_H__
# define CWDLIBRARY_H__

# include <Windows.h>
# include "DLibrary.h"

class CWDLibrary : public IDLibrary, private ADLibrary {

	HMODULE			handler;

public:

	CWDLibrary(int _id, const char *_name, const char *_path) :
		ADLibrary(_id, _name, _path) {
	}

	const char			*getName(void) const;

	bool				load(void);
	bool				close(void);
	Dictionary			getDictionary(void);
};

#endif /* !CWDLIBRARY_H__ */
