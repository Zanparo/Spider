#ifndef CUDLIBRARY_H__
# define CUDLIBRARY_H__

# include "DLibrary.h"

class CUDLibrary : public IDLibrary, private ADLibrary {

	void				*handler;

public:

	CUDLibrary(int _id, const char *_name, const char *_path) :
		ADLibrary(_id, _name, _path) {}

	const char			*getName(void) const;

	bool				load(void);
	bool				close(void);
	Dictionary			getDictionary(void);
};

#endif /* !CUDLIBRARY_H__ */
