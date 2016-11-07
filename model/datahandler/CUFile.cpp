/**
 * Project FileManager DLL
 */


#include "CUFile.h"

/**
 * CUFile implementation
 */


/**
 * Open the Unix file. Returns bool if succeed.
 * @return bool
 */
bool CUFile::open() {
    return false;
}

/**
 * Close the Unix file. Returns true if succeed.
 * @return bool
 */
bool CUFile::close() {
    return false;
}

/**
 * Read the n characters in the file, depending on the int parameter. Returns the string read.
 * @param int
 * @return string
 */
std::string		CUFile::read(int nb_byte) {
    return "";
}

/**
 * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
 * @param string
 * @return int
 */
int CUFile::write(std::string string) {
    return 0;
}