/**
 * Project FileManager DLL
 */


#include "DataModelHandler.h"

/**
 * DataModelHandler implementation
 */


/**
 * Constructor of DataModelHandler.
 */
DataModelHandler::DataModelHandler() {

}

DataModelHandler::~DataModelHandler() {

}

/**
 * Returns the list of DataModel pointers. 
 * @return list<DataModel*>
 */
std::list<DataModel*> DataModelHandler::getDataModels() {
	return this->_dataModels;
}