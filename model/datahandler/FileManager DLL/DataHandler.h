/**
 * Project FileManager DLL
 */


#ifndef _DATAHANDLER_H
#define _DATAHANDLER_H

class DataHandler {
public: 
    
    /**
     * Constructor of DataHandler class.
     */
    void DataHandler();
    
    /**
     * Initialization of DataHandler class.
     */
    bool Init();
private: 
    DataModelHandler _dataModelHandler;
    FileHandler _fileHandler;
    List<ISerializer*> _serializers;
};

#endif //_DATAHANDLER_H