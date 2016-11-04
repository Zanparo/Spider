/**
 * Project FileManager DLL
 */


#include "CWFile.h"
#include <iostream>

/**
 * CWFile implementation
 */
CWFile::CWFile(std::string const& path) : AFile(path) {
	this->_file.open(path);
}

CWFile::~CWFile() {

}

/**
 * Open the Windows file. Returns bool if succeed.
 * @return bool
 */
bool CWFile::open(std::string const& path) {
	std::cout << "Opening : " << path << std::endl;
	this->_file.open(path, std::ios::in | std::ios::out | std::ios::ate);
	if (this->_file.is_open() == false)
		return (false);
	return (true);
}

bool CWFile::open() {
	this->_file.open(this->_filename);
	if (this->_file.is_open() == false)
		return (false);
	return (true);
}
/**
 * Close the Windows file. Returns true if succeed.
 * @return bool
 */
bool CWFile::close() {
	this->_file.close();
	return (true);
}

/**
 * Read the n characters in the file, depending on the int parameter. Returns the string read.
 * @param int
 * @return string
 */
std::string CWFile::read(int size) {
	if (this->_file.is_open() == false)
		throw std::exception("Uninitialized file.");
	this->_file.seekg(0, _file.end);
	if (this->_file.tellg() < size) {
		size = this->_file.tellg();
	}
	this->_file.seekg(0, _file.beg);
	std::cout << "Size read is : " << size << std::endl;
	char *buffer = new char [size + 1];
	this->_file.read(buffer, size);
	buffer[size] = 0;
	std::string ret(buffer);
	delete[] buffer;
	return (ret);
}

/**
 * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
 * @param string
 * @return int
 */
int CWFile::write(std::string const& towrite) {
	if (this->_file.is_open() == false)
		throw std::exception("Uninitialized file.");
	std::cout << "writing this: " << towrite << std::endl;
	this->_file.write(towrite.c_str(), towrite.length());
	return (towrite.length());
}