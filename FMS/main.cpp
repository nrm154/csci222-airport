#include "mainwindow.h"
#include "uiloginscreen.h"
#include <QApplication>
#include <QtSql>

#include "ConfigurationSettings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConfigurationSettings::LoadSettings();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(ConfigurationSettings::getDBHostname().c_str());
    db.setDatabaseName(ConfigurationSettings::getDBDatabaseName().c_str());
    db.setUserName(ConfigurationSettings::getDBUsername().c_str());
    db.setPassword(ConfigurationSettings::getDBPassword().c_str());
    db.open();
    //qDebug() << db.lastError().text();
    //qDebug() << "Database name: " << ConfigurationSettings::getDBHostname().c_str();


     QSqlQuery query;
     query.exec("SELECT * from USER");

     while (query.next()) {
            qDebug() << query.value(0).toString() << query.value(1).toString();
     }

     db.close();

     UILoginScreen w;
     w.show();

    return a.exec();
}
