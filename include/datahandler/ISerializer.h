/**
 * Project FileManager DLL
 */


#ifndef _ISERIALIZER_H
#define _ISERIALIZER_H

class ISerializer {
public: 
    
    /**
     * Virtual pure function to encapsulate several serialization functions. 
     * 
     * @param DataModel*
     */
    virtual std::string serialize(DataModel* c) = 0;
};

#endif //_ISERIALIZER_H