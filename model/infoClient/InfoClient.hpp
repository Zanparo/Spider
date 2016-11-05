#ifndef _INFOCLIENT_HPP
# define _INFOCLIENT_HPP
#include <string>
#include <map>
#include <stdio.h>
#include <windows.h>
#include <IPHlpApi.h>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <io.h>
#include <codecvt>
#include <stdexcept>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Advapi32.lib")


#define GET_UUID "wmic csproduct get uuid"
#define DOTNETVER_REG L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v4\\Full\\"
#define DOTNETVER_KEY L"Release"
#define OSTYPE_REG L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion"
#define OSTYPE_KEY L"ProductName"

class InfoClient {
public:

	enum InfoType {
		OSTYPE,
		HOSTNAME,
		DOTNETVER,
		MACADDR,
		UUID
	};

	InfoClient();
	~InfoClient();
	std::map<InfoClient::InfoType, std::string> routine();
	std::string getOSType();
	std::string getHostname();
	std::string getdotNETver();
	std::string getMacAddr();
	std::string getUUID();

private:

};

#endif