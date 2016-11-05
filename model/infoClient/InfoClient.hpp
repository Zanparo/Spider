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
#include <VersionHelpers.h>
#include <winver.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "iphlpapi.lib")

class InfoClient {
public:

	enum InfoType {
		OSTYPE,
		HOSTNAME,
		DOTNETVER,
		MACADDR,
		EMAIL_ADDR
	};

	InfoClient();
	~InfoClient();
	std::map<InfoClient::InfoType, std::string> routine();
	std::string getOSType();
	std::string getHostname();
	std::string getdotNETver();
	std::string getMacAddr();
	std::string getMailAddr();

private:

};

#endif