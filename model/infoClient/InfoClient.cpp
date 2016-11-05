#include "InfoClient.hpp"

InfoClient::InfoClient() {
}

InfoClient::~InfoClient() {
}

std::map<InfoClient::InfoType, std::string> InfoClient::routine() {
	std::map<enum InfoClient::InfoType, std::string> itemlist;
	itemlist.insert(std::pair<InfoClient::InfoType, std::string>(OSTYPE, this->getOSType()));
	itemlist.insert(std::pair<InfoClient::InfoType, std::string>(HOSTNAME, this->getHostname()));
	itemlist.insert(std::pair<InfoClient::InfoType, std::string>(DOTNETVER, this->getdotNETver()));
	itemlist.insert(std::pair<InfoClient::InfoType, std::string>(MACADDR, this->getMacAddr()));
	itemlist.insert(std::pair<InfoClient::InfoType, std::string>(UUID, this->getUUID()));
	return (itemlist);
}

std::string InfoClient::getOSType() {
	HKEY hKey;
	DWORD dwtype = REG_SZ;
	LONG lRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, OSTYPE_REG, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);
	DWORD bufferSize = 512;
	char result[512] = { 0 };
	if (lRes != 0) {
		std::cout << "lres = " << lRes << std::endl;
		return (std::string("N/A"));
	}
	LONG nError = RegQueryValueEx(hKey, OSTYPE_KEY, NULL, &dwtype, (LPBYTE)&result, &bufferSize);
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
	LONG lRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, DOTNETVER_REG, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);
	DWORD result(0);
	DWORD bufferSize(sizeof(DWORD));
	if (lRes != 0) {
		return (std::string("N/A"));
	}
	LONG nError = RegQueryValueEx(hKey, DOTNETVER_KEY, 0, NULL, reinterpret_cast<LPBYTE>(&result), &bufferSize);
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
