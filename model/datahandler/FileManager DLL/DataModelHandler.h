/**
 * Project FileManager DLL
 */


#ifndef _DATAMODELHANDLER_H
#define _DATAMODELHANDLER_H

#include "DataHandler.h"


class DataModelHandler {
public: 
    
    /**
     * Constructor of DataModelHandler.
     */
    void DataModelHandler();
    
    /**
     * Returns the list of DataModel pointers.
     */
    list<DataModel*> getDataModels();
private: 
    /**
     * Contains DataModels used by DataHandler.
     */
    List<DataModel*> _dataModels;
    DataHandler _dataModelHandler;
};

#endif //_DATAMODELHANDLER_H