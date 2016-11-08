/**
 * Project FileManager DLL
 */

#ifndef _FILEHANDLER_H
# define _FILEHANDLER_H

# include <iostream>
# include <string>
# include <list>

////////////////////////////////////////////////////
// IFILE
////////////////////////////////////////////////////

class IFile {
public:

	/**
	* Open the file and return true for sucess
	*/
	virtual bool			open(void) = 0;

	/**
	* Close a file. Returns true if suceed.
	*/
	virtual bool			close(void) = 0;

	/**
	* Erase a file. Returns true if suceed.
	*/
	virtual bool			erase(void) = 0;

	/**
	* Read the n characters in the file, depending on the int parameter. Returns the string read.
	* @param int
	*/
	virtual std::string		read(int n) = 0;

	/**
	* Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
	* @param string
	*/
	virtual int				write(std::string const& towrite) = 0;
};


////////////////////////////////////////////////////
// AFILE
////////////////////////////////////////////////////

class AFile {
public:

	int				id;
	std::string		path;
	int				size;

	AFile(std::string const& _path) : path(_path) {};
};


////////////////////////////////////////////////////
// File Handler
////////////////////////////////////////////////////

typedef std::list<IFile *>	Library;

class FileHandler {

	/**
	* List of IFile*. Used to contains pointers on files needed by the DataHandler.
	*/
	Library			stream;

	/**
	* Byte per file. Used to setup stream's files limit.
	*/
	std::string		streamFolder;

	/**
	* Byte per file. Used to setup stream's files limit.
	*/
	unsigned int	bytePerFile;

public:

	FileHandler() {};

	int			initStream(std::string, unsigned int);
	void		addFileToStream(const std::string);
	int			insertDataToStream(const std::string);
};

#endif //_FILEHANDLER_H