/**
 * Project FileManager DLL
 */


#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>
#include "CUFileHandler.h"

int												CUFileHandler::initStream(std::string _streamFolder, unsigned int _bytePerFile)
{
	// WIN32_FIND_DATA								ffd;
	// LARGE_INTEGER								filesize;
	// HANDLE										hFind = INVALID_HANDLE_VALUE;
	// DWORD										dwError = 0;
	// int											n_files = 0;
	// std::map<std::string, long long>			match_files;
	// std::map<std::string, long long>::iterator	it;

	// this->index = 0;
	// this->streamFolder = _streamFolder;
	// this->bytePerFile = _bytePerFile;
	// if ((hFind = FindFirstFile((this->streamFolder + "*").c_str(), &ffd)) == INVALID_HANDLE_VALUE)
		// return (0);
	// while (FindNextFile(hFind, &ffd) != 0)
	// {
		// if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		// {
			// ++n_files;
			// filesize.LowPart = ffd.nFileSizeLow;
			// filesize.HighPart = ffd.nFileSizeHigh;
			// if (!strncmp(ffd.cFileName, ".UNIX_", 9))
				// match_files[ffd.cFileName] = filesize.QuadPart;
		// }
	// }
	// for (it = match_files.begin(); it != match_files.end(); ++it)
		// this->stream.push_back(new CUFile(this->streamFolder + (*it).first, (*it).second));
	// FindClose(hFind);
	// return (n_files);
	return (0);
}

bool					CUFileHandler::writeFromFile(IFile *current, std::string &raw)
{
	std::time_t			t;
	std::stringstream	tm;
	std::string			tmsp;
	int					wrote = 0;

	t = (std::time(0) * 10) + this->index++;
	tm.str("");
	tm << t;
	tmsp = tm.str();
	if (!current) {
		current = new CUFile(this->streamFolder + std::string(".UNIX_") + tmsp, 0);
		this->stream.push_back(current);
	}
	if (!current->open())
		return (false);
	while (raw.size())
	{
		if (-1 == (wrote = current->write(raw, this->bytePerFile - current->getSize())))
			return (false);
		raw = raw.substr(wrote, std::string::npos);
		if (raw.size()) {
			t = (std::time(0) * 10) + index++;
			tm.str("");
			tm << t;
			tmsp = tm.str();
			current = new CUFile(this->streamFolder + std::string(".UNIX_") + tmsp, 0);
			if (!current->open())
				return (false);
			this->stream.push_back(current);
		}
	}
	this->closeStream();
	return (true);
}

bool		CUFileHandler::insertDataToStream(std::string raw)
{
	IFile	*file;

	if (!this->stream.size())
		return (writeFromFile(NULL, raw)); // Create first one Then Append
	else
	{
		file = this->stream.back();
		if (file->getSize() >= this->bytePerFile)
			return (writeFromFile(NULL, raw)); // Create a new one
		else {
			std::cout << "Last file size : " << file->getSize() << std::endl;
			return (writeFromFile(file, raw));
		}
	}
	return (false);
}

std::string							CUFileHandler::extractDataFromStream(int nbFile)
{
	std::string						result = std::string("");
	std::list<IFile *>::iterator	file;
	int								i = 0;

	if (!this->stream.size())
		return (std::string(""));
	for (file = this->stream.begin(); file != this->stream.end() && i++ < nbFile; ++file) {
		if ((*file)->open())
			result += (*file)->read();
	}
	this->closeStream();
	return (result);
}

void								CUFileHandler::removeLocalData(int nbFile)
{
	std::list<IFile *>::iterator	file;
	int								i = 0;

	while (this->stream.size() && i < nbFile)
	{
		(*this->stream.begin())->erase();
		this->stream.pop_front();
		++i;
	}
}

void								CUFileHandler::closeStream(void)
{
	std::list<IFile *>::iterator	file;

	for (file = this->stream.begin(); file != this->stream.end(); ++file) {
		(*file)->close();
	}
}

void								CUFileHandler::showStream(void)
{
	std::list<IFile *>::iterator	file;

	std::cout << "##################################################" << std::endl;
	for (file = this->stream.begin(); file != this->stream.end(); ++file) {
		(*file)->open();
		std::cout << (*file)->getPath() << std::endl;
		std::cout << "    { " << (*file)->getSize() << " : " << (*file)->read() << " }" << std::endl;
	}
	std::cout << "##################################################" << std::endl;
	this->closeStream();
}