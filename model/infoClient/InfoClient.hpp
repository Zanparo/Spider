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
#pragma comment(lib, "ws2_32.lib")
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