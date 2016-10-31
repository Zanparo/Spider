/**
 * Project FileManager DLL
 */


#ifndef _DATAMODELFACTORY_H
#define _DATAMODELFACTORY_H

class DataModelFactory {
public: 
    
    /**
     * Function used to create a DataModel instance from a APacket pointer.
     * 
     * @param APacket*
     */
    static DataModel* create(void APacket*);
    
    /**
     * Function used to create a DataModel instance from a AEvent pointer.
     * 
     * @param AEvent*
     */
    static DataModel* create(void AEvent*);
};

#endif //_DATAMODELFACTORY_H