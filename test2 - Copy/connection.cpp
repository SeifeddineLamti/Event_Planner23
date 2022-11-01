#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
    db = QSqlDatabase :: addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Projet2A");
    db.setUserName("ons");
    db.setPassword("esprit18");

    if (db.open()) test=true;
    return test;
}

void Connection::closeconnection(){db.close();}
