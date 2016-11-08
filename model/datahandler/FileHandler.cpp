/**
 * Project FileManager DLL
 */

#ifdef __linux__
#include "CUFile.h"

int		initStream(void)
{
	return (0);
}

#elif _WIN32
#include "CWFile.h"

int						FileHandler::initStream(std::string _streamFolder, unsigned int _bytePerFile)
{
	WIN32_FIND_DATA		ffd;
	LARGE_INTEGER		filesize;
	HANDLE				hFind = INVALID_HANDLE_VALUE;
	DWORD				dwError = 0;
	int					n_files = 0;

	this->streamFolder = _streamFolder;
	this->bytePerFile = _bytePerFile;
	if ((hFind = FindFirstFile(this->streamFolder.c_str(), &ffd)) == INVALID_HANDLE_VALUE)
		return (0);
	while (FindNextFile(hFind, &ffd) != 0)
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			std::cout << "Directory: " << ffd.cFileName << std::endl;
		else
		{
			++n_files;
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			std::cout << ffd.cFileName << " : " << filesize.QuadPart << " bytes.";
		}
	}
	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
		std::cout << "Error at initialisation" << std::endl;

	FindClose(hFind);
	return (n_files);
}

#endif

void		FileHandler::addFileToStream(const std::string path)
{
	IFile	*file;

	#if defined(WIN32)
		file = new CWFile(path);
	#elif(UNIX)
		file = new CUFile(path);
	#endif
		this->stream.push_back(file);
}

int		FileHandler::insertDataToStream(const std::string raw)
{
	return (0);
}
