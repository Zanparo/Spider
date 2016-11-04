#ifndef DLDICTIONARY_H__
# define DLDICTIONARY_H__

# include <map>

//
// SPIDER DYNAMIC LIBRARY STANDARDS
//
// Dynamic libraries MUST implement the following function :
//   Dictionary    getDictionary(void);
//

# define DICTIONARY_GETTER	"getDictionary"

typedef std::map<std::string, void *>*		Dictionary;

// Get Dictionary Function
# ifdef __linux__
	typedef Dictionary	(*GET_DICTIONARY)(void);
# elif _WIN32
	typedef __declspec(dllimport) Dictionary	(__cdecl *GET_DICTIONARY)(void);
# endif

#endif /* !DLDICTIONARY_H__ */
