#ifndef _I_INFO_CLIENT_H
#define _I_INFO_CLIENT_H
#include <map>
#include <string>

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

#endif