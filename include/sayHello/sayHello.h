#ifndef SAYHELLO_H__
# define SAYHELLO_H__

# ifdef __linux__ 
   // Silence is golden
# elif _WIN32
#  include <windows.h>
# endif
# include <iostream>
# include <string>
# include "DLDictionary.h"

//
// SPIDER DYNAMIC LIBRARY STANDARDS
//
// Functions type MUST be defined as the name of the function preceded by "_"
//

typedef		void (* _sayHelloFrom)(std::string);

#endif /* !SAYHELLO_H__ */