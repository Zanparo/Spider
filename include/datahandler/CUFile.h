/**
 * Project FileManager DLL
 */


#ifndef _CUFILE_H
#define _CUFILE_H

#include "AFile.h"


class CUFile: public AFile {
public: 
    
    /**
     * Open the Unix file. Returns bool if succeed.
     */
    bool open();
    
    /**
     * Close the Unix file. Returns true if succeed.
     */
    bool close();
    
    /**
     * Read the n characters in the file, depending on the int parameter. Returns the string read.
     * @param int
     */
    string read(void int);
    
    /**
     * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
     * @param string
     */
    int write(void string);
private: 
    int _fd;
};

#endif //_CUFILE_H