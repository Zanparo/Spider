#include "AFile.h"

AFile::AFile() {
}
AFile::AFile(std::string const &path) {
	this->_filename = path;
}

AFile::~AFile() {

}