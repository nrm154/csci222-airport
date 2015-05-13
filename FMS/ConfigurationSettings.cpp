#include "ConfigurationSettings.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

std::string ConfigurationSettings::DB_HOSTNAME;
std::string ConfigurationSettings::DB_PORT;
std::string ConfigurationSettings::DB_DATABASE_NAME;
std::string ConfigurationSettings::DB_USERNAME;
std::string ConfigurationSettings::DB_PASSWORD;

std::string ConfigurationSettings::getDBHostname()
{
	return DB_HOSTNAME;
}

std::string ConfigurationSettings::getDBPort()
{
	return DB_PORT;
}

std::string ConfigurationSettings::getDBDatabaseName()
{
	return DB_DATABASE_NAME;
}

std::string ConfigurationSettings::getDBUsername()
{
	return DB_USERNAME;
}

std::string ConfigurationSettings::getDBPassword()
{
	return DB_PASSWORD;
}

std::string ConfigurationSettings::getDBURL()
{
	return "tcp://" + DB_HOSTNAME + ":" + DB_PORT;
}

bool ConfigurationSettings::LoadSettings()
{
	ifstream settingsFile("config.cfg");

	if(settingsFile.is_open() == false)
		return false;

	string settingName;
	string value;
	while(settingsFile.good())
	{
		settingsFile >> settingName;
		settingsFile >> value;
		if(settingName == "db-hostname")
			ConfigurationSettings::DB_HOSTNAME = value;
		else if(settingName == "db-port")
			ConfigurationSettings::DB_PORT = value;
		else if(settingName == "db-database-name")
			ConfigurationSettings::DB_DATABASE_NAME = value;
		else if(settingName == "db-username")
			ConfigurationSettings::DB_USERNAME = value;
		else if(settingName == "db-password")
			ConfigurationSettings::DB_PASSWORD = value;
		else
			cout << "WARNING: Unknown variable in configuration file: " << settingName << endl;
	}

	settingsFile.close();

	return true;
}