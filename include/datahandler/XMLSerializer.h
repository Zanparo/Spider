#ifndef XML_SERIALIZER_H
# define XML_SERIALIZER_H

# include <iostream>
# include <map>
# include "Serializer.h"
//# include "AEvent.h"

typedef	std::map < std::string, std::string > XMLTree;

class XMLSerializer : public ISerializer {

	std::string		createXML(XMLTree);

public:

	//std::string	serializeEvent(AEvent *) const;

	//Packet*		createPacket(std::string) const;
};

#endif //XML_SERIALIZER_H