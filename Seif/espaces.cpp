#include "espaces.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Espaces::Espaces()
{
ID_ESPACE=0;
CAPACITE=0;
NOM=" ";
TYPE=" ";
LIEU=" ";
DATE_LOCATION=" ";
PRIX_LOCATION=0;
}
Espaces::Espaces(int ID_ESPACE,int CAPACITE,QString NOM,QString TYPE,QString LIEU,QString DATE_LOCATION,float PRIX_LOCATION)
{
    this->ID_ESPACE=ID_ESPACE;
    this->CAPACITE=CAPACITE;
    this->NOM=NOM;
    this->TYPE=TYPE;
    this->LIEU=LIEU;
    this->DATE_LOCATION=DATE_LOCATION;
    this->PRIX_LOCATION=PRIX_LOCATION;
}

bool Espaces::ajouter()
{


    QSqlQuery query;
          query.prepare("INSERT INTO ESPACES (ID_ESPACE,TYPE, NOM, LIEU, CAPACITE, PRIX_LOCATION, DATE_LOCATION)"
                        "VALUES (:ID_ESPACE, :TYPE, :NOM, :LIEU, :CAPACITE, :PRIX_LOCATION,:DATE_LOCATION)");
          query.bindValue(":ID_ESPACE", ID_ESPACE);
          query.bindValue(":TYPE", TYPE);
          query.bindValue(":NOM", NOM);
           query.bindValue(":LIEU", LIEU);
          query.bindValue(":CAPACITE", CAPACITE);
           query.bindValue(":PRIX_LOCATION", PRIX_LOCATION);
          query.bindValue(":DATE_LOCATION", DATE_LOCATION);


          return query.exec();
}

QSqlQueryModel * Espaces::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


          model->setQuery("SELECT ID_ESPACE,TYPE, NOM, LIEU, CAPACITE, PRIX_LOCATION, DATE_LOCATION FROM Espaces ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Capacite"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix De Location"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date De Location"));



    return model;
}
bool Espaces::Supprimer(QString x)
{
    QSqlQuery query;
    query.prepare("Delete from espaces where id_espace = :id");
    query.bindValue(":id",x);
    return query.exec();

}
bool Espaces::modifier(QString x){
    QSqlQuery query;
          query.prepare("UPDATE ESPACES SET type = :TYPE , nom = :NOM , lieu = :LIEU , capacite = :CAPACITE,prix_location = :PRIX_LOCATION, date_location=:DATE_LOCATION where id_espace = :x");
          query.bindValue(":x", x);
          query.bindValue(":TYPE", TYPE);
          query.bindValue(":NOM", NOM);
           query.bindValue(":LIEU", LIEU);
          query.bindValue(":CAPACITE", CAPACITE);
           query.bindValue(":PRIX_LOCATION", PRIX_LOCATION);
          query.bindValue(":DATE_LOCATION", DATE_LOCATION);


          return query.exec();






}

