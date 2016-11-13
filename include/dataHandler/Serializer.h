#ifndef _ISERIALIZER_H
# define _ISERIALIZER_H

# include <iostream>
# include "AEvent.h"

class ISerializer {
public: 

	virtual std::string	serializeEvent(std::string, std::string) = 0;
};

#endif //_ISERIALIZER_H