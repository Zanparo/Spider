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

	virtual long long	getSize(void) const = 0;
	virtual std::string	getPath(void) const = 0;

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
	virtual std::string		read() = 0;

	/**
	* Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
	* @param string
	*/
	virtual int				write(std::string const& towrite) = 0;

	virtual int				write(std::string const&, long long) = 0;
};


////////////////////////////////////////////////////
// AFILE
////////////////////////////////////////////////////

class AFile {
public:

	std::string		path;
	long long		size;

	AFile(std::string const& _path, long long _size)
		: path(_path), size(_size) {};
};


////////////////////////////////////////////////////
// File Handler
////////////////////////////////////////////////////

typedef std::list<IFile *>	Library;

class	IFileHandler {

public:

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

	virtual int			initStream(std::string, unsigned int) = 0;
	virtual void		closeStream() = 0;
	virtual void		showStream(void) = 0;
	virtual bool		insertDataToStream(std::string) = 0;
	virtual std::string	extractDataFromStream(int) = 0;
	virtual void		removeLocalData(int) = 0;

};

#endif //_FILEHANDLER_H