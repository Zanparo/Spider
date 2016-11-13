#ifndef XML_SERIALIZER_H
# define XML_SERIALIZER_H

# include <iostream>
# include <map>
# include "Serializer.h"

typedef	std::map < std::string, std::string > XMLTree;

class XMLSerializer : public ISerializer {

	std::string		createXML(XMLTree);

public:

	XMLSerializer();

	std::string	serializeEvent(std::string, std::string);
};

#endif //XML_SERIALIZER_H