/**
 * Project FileManager DLL
 */


#include "CWFile.h"

/**
 * CWFile implementation
 */
CWFile::CWFile() {

}

CWFile::~CWFile() {

}

/**
 * Open the Windows file. Returns bool if succeed.
 * @return bool
 */
bool CWFile::open(std::string const& path) {
	this->_file = CreateFile(path.c_str(), (GENERIC_READ | GENERIC_WRITE), FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (this->_file == INVALID_HANDLE_VALUE)
		return (false);
	return (true);
}

/**
 * Close the Windows file. Returns true if succeed.
 * @return bool
 */
bool CWFile::close() {
	if (this->_file == INVALID_HANDLE_VALUE)
		throw std::exception("Uninitialized file.");
	CloseHandle(_file);
	return (true);
}

/**
 * Read the n characters in the file, depending on the int parameter. Returns the string read.
 * @param int
 * @return string
 */
std::string CWFile::read(int n) {
	if (this->_file == INVALID_HANDLE_VALUE)
		throw std::exception("Uninitialized file.");
	char buffer[n + 1] = { 0 };
	int	 nb_read = 0;
	if (ReadFile(this->_file, buffer, n, &nb_read, NULL) == false)
		throw std::exception("Invalid read.");
	buffer[nb_read + 1] = 0;
	return (std::string(buffer));
}

/**
 * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
 * @param string
 * @return int
 */
int CWFile::write(std::string const& towrite) {
	if (this->_file == INVALID_HANDLE_VALUE)
		throw std::exception("Uninitialized file.");
	int nb_written = 0;
	if (WriteFile(_file, towrite.c_str(), towrite.length(), &nb_written, NULL) == false)
		throw std::exception("Invalid write");
	return (nb_written);
}