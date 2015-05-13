#ifndef CONFIGURATION_SETTINGS_H
#define CONFIGURATION_SETTINGS_H

#include <string>

class ConfigurationSettings
{
protected:
	static std::string DB_HOSTNAME;
	static std::string DB_PORT;
	static std::string DB_DATABASE_NAME;
	static std::string DB_USERNAME;
	static std::string DB_PASSWORD;
public:
	static bool LoadSettings();

	static std::string getDBHostname();
	static std::string getDBPort();
	static std::string getDBDatabaseName();
	static std::string getDBUsername();
	static std::string getDBPassword();
	static std::string getDBURL();
};


#endif // header guard
