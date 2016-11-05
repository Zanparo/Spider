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
	itemlist.insert(std::pair<InfoClient::InfoType, std::string>(EMAIL_ADDR, this->getMailAddr()));
	return (itemlist);
}

std::string InfoClient::getOSType() {
	DWORD val;
	DWORD lpdval;
	LPVOID infos;

	val = GetFileVersionInfoSize((LPCWSTR)"C:/Windows/system32/kernel32.dll", &lpdval);
	LPVOID ptr = new BYTE[val];
	infos = new BYTE[val];
	if ((GetFileVersionInfo((LPCWSTR)"C:/Windows/system32/kernel32.dll", lpdval, val, ptr)) == 0) {
		std::cout << "GetFileVersionInfo : " << GetLastError() << std::endl;
		return (std::string("N/A"));
	}
	UINT dwbytes;
	if ((VerQueryValue(ptr, (LPCWSTR)"\\StringFileInfo\\ProductVersion", &infos, &dwbytes)) == 0) {
		std::cout << "VerQueryValue : " << GetLastError() << std::endl;
		return (std::string("N/A"));
	}
	std::cout << infos << std::endl;
	return std::string("N/A");
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
	else {
		perror("gethostname");
		std::cout << WSAGetLastError() << std::endl;
	}
	return std::string("N/A");
}

std::string InfoClient::getdotNETver() {
	return std::string("N/A");
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

std::string InfoClient::getMailAddr() {
	return std::string("N/A");
}
