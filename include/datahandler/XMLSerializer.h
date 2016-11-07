/**
 * Project FileManager DLL
 */


#ifndef _XMLSERIALIZER_H
#define _XMLSERIALIZER_H

#include "ISerializer.h"


class XMLSerializer: public ISerializer {
public: 
    
    /**
     * Constructor of XMLSerializer.
     */
    XMLSerializer();
    
    /**
     * Serialization function. Take a pointer to a DataModel instance and returns the serialized string.
     * 
     * @param DataModel*
     */
    std::string		serialize(DataModel *);
};

#endif //_XMLSERIALIZER_H