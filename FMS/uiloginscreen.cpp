#include "uiloginscreen.h"
#include "ui_uiloginscreen.h"

#include "ConfigurationSettings.h"

#include <QtSql>

UILoginScreen::UILoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UILoginScreen)
{
    ui->setupUi(this);
    connect(ui->btnLogin, SIGNAL (released()),this, SLOT (LoginPressed()));
}

UILoginScreen::~UILoginScreen()
{
    delete ui;
}

void UILoginScreen::LoginPressed()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(ConfigurationSettings::getDBHostname().c_str());
    db.setDatabaseName(ConfigurationSettings::getDBDatabaseName().c_str());
    db.setUserName(ConfigurationSettings::getDBUsername().c_str());
    db.setPassword(ConfigurationSettings::getDBPassword().c_str());
    db.open();

    QString queryStmt = "select userid, role from USER where username=\"";
    queryStmt += username;
    queryStmt += "\" AND password=\"";
    queryStmt += password;
    queryStmt += "\";";

    QSqlQuery query;
    query.exec(queryStmt);

    while (query.next()) {
           qDebug() << query.value(0).toString() << query.value(1).toString();
    }

    db.close();

}
