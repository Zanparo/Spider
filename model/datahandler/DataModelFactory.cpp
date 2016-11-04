/**
 * Project FileManager DLL
 */


#include "DataModelFactory.h"

/**
 * DataModelFactory implementation
 */


/**
 * Function used to create a DataModel instance from a APacket pointer.
 * 
 * @param APacket*
 * @return DataModel*
 */
DataModel* DataModelFactory::create(APacket*) {
    return NULL;
}

/**
 * Function used to create a DataModel instance from a AEvent pointer.
 * 
 * @param AEvent*
 * @return DataModel*
 */
DataModel* DataModelFactory::create(AEvent*) {
    return NULL;
}
