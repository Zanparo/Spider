/**
 * Project FileManager DLL
 */

#include <iostream>
#include "CUFile.h"

/**
 * CUFile implementation
 */

long long	CUFile::getSize(void) const
{
	return (this->size);
}

std::string	CUFile::getPath(void) const
{
	return (this->path);
}

/**
 * Open the Windows file. Returns bool if succeed.
 * @return bool
 */

bool		CUFile::open()
{
	this->file.open(this->path, std::fstream::out | std::fstream::in | std::fstream::app);
	return (this->file.is_open());
}

/**
 * Close the Windows file. Returns true if succeed.
 * @return bool
 */
bool		CUFile::close()
{
	this->file.close();
	return (true);
}

/**
* Erase the file. Returns true if succeed.
* @return bool
*/
bool		CUFile::erase()
{
	remove(this->path.c_str());
	return (true);
}

/**
 * Read the n characters in the file, depending on the int parameter. Returns the string read.
 * @param int
 * @return string
 */
std::string	CUFile::read(int size)
{
	char *buffer;

	if (!this->file.is_open())
		return (std::string(""));
	this->file.seekg(0, file.end);
	if (this->file.tellg() < size)
		size = this->file.tellg();
	this->file.seekg(0, file.beg);
	buffer = new char[size + 1];
	this->file.read(buffer, size);
	buffer[size] = '\0';
	std::string ret(buffer);
	delete[] buffer;
	return (ret);
}

std::string	CUFile::read()
{
	char	*buffer;
	int		size;

	if (!this->file.is_open())
		return (std::string(""));
	this->file.seekg(0, file.end);
	size = this->file.tellg();	
	this->file.seekg(0, file.beg);
	buffer = new char[size + 1];
	this->file.read(buffer, size);
	buffer[size] = '\0';
	std::string ret = std::string(buffer);
	delete[] buffer;
	return (ret);
}

/**
 * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
 * @param string
 * @return int
 */
int		CUFile::write(std::string const& data)
{
	if (!data.size())
		return (-1);
	if (!this->file.is_open())
		return (-1);
	this->file.write(data.c_str(), data.length());
	this->size += data.length();
	return (data.length());
}

int		CUFile::write(std::string const& data, long long nBytes)
{
	if (!data.size())
		return (0);
	if (nBytes > data.size())
		nBytes = data.size();
	if (!this->file.is_open() || nBytes > data.size())
		return (-1);
	this->file.write(data.c_str(), nBytes);
	this->size += nBytes;
	return (nBytes);
}