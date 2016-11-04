/**
 * Project FileManager DLL
 */


#ifndef _DATAMODELFACTORY_H
#define _DATAMODELFACTORY_H

#include "DataModel.h"
#include <iostream>

class APacket { };
class AEvent { };
class DataModelFactory {
public: 
    
    /**
     * Function used to create a DataModel instance from a APacket pointer.
     * 
     * @param APacket*
     */
     DataModel* create(APacket* c);
    
    /**
     * Function used to create a DataModel instance from a AEvent pointer.
     * 
     * @param AEvent*
     */

	 DataModel* create(AEvent* c);
};

#endif //_DATAMODELFACTORY_H