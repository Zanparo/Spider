/**
 * Project FileManager DLL
 */


#ifndef _CUFILE_H
# define _CUFILE_H

# include "FileHandler.h"


class CUFile: public AFile {

	int				_fd;

public: 
    
    /**
     * Open the Unix file. Returns bool if succeed.
     */
    bool			open();
    
    /**
     * Close the Unix file. Returns true if succeed.
     */
    bool			close();
    
    /**
     * Read the n characters in the file, depending on the int parameter. Returns the string read.
     * @param int
     */
    std::string		read(int n_byte);
    
    /**
     * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
     * @param string
     */
    int				write(std::string string);
};

#endif //_CUFILE_H