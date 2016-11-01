/**
 * Project FileManager DLL
 */


#ifndef _DATAHANDLER_H
#define _DATAHANDLER_H

#include "DataModelHandler.h"
#include "FileHandler.h"
#include "ISerializer.h"
#include <list>

class DataHandler {
public: 
    
    /**
     * Constructor of DataHandler class.
     */
    DataHandler();
    
    /**
     * Initialization of DataHandler class.
     */
    bool Init();
private: 
    DataModelHandler _dataModelHandler;
    FileHandler _fileHandler;
    std::list<ISerializer*> _serializers;
};

#endif //_DATAHANDLER_H