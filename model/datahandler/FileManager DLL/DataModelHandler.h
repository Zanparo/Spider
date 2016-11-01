/**
 * Project FileManager DLL
 */


#ifndef _DATAMODELHANDLER_H
#define _DATAMODELHANDLER_H

#include "DataModel.h"
#include <list>

class DataModelHandler {
public: 
    /**
     * Constructor of DataModelHandler.
     */
    DataModelHandler();
	~DataModelHandler();
    
    /**
     * Returns the list of DataModel pointers.
     */
    std::list<DataModel*> getDataModels();
private: 
    /**
     * Contains DataModels used by DataHandler.
     */
    std::list<DataModel*> _dataModels;
};

#endif //_DATAMODELHANDLER_H