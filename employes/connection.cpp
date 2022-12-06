#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("evenement");//evenement
db.setUserName("yosr");//inserer nom de l'utilisateur:yosr
db.setPassword("yosr");//inserer mot de passe de cet utilisateur:yosr

if (db.open())
test=true;





    return  test;
}
