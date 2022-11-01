#include "connection.h"
#include <iostream>
#include <QApplication>
#include <QtDebug>

using std::cout;


Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setConnectOptions();
db.setDatabaseName("Source_Projet2A");
db.setUserName("hazem");//inserer nom de l'utilisateur
db.setPassword("hazem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;






   return  test;
}
//void Connection::closeConnection()
//{
//    db.close();
//}
