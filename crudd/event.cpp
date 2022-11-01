#include "event.h"
#include <QSqlQuery>
#include <QtDebug>
#include <iostream>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFlags>
#include "connection.h"


using namespace std;
//Etudiant::Etudiant()
//{
//id=0;nom="";prenom="";
//}

Event::Event(int id,QString type,QString date,int nombre_inv,int budget)
{
    this->id=id;
    this->type=type;
    this->date=date;
    this->nombre_inv=nombre_inv;
    this->budget=budget;
}
int Event::getid()
{
    return id;
}
QString Event::gettype()
{
    return type;
}
QString Event::getdate()
{
    return date;
}
int Event::getnombre_inv()
{
    return nombre_inv;
}
int Event::getbudget()
{
    return budget;
}
void Event::setid(int id)
{
    this->id=id;
}
void Event::settype(QString type)
{
    this->type=type;
}
void Event::setdate(QString date)
{
    this->date=date;
}
void Event::setnombre_inv(int nombre_inv)
{
    this->nombre_inv=nombre_inv;
}
//bool Etudiant::ajouter()
//{
//    bool test=false;
//    QSqlQuery query;
//    QString res = QString::number(id);
//          query.prepare("INSERT INTO etudiant (id, nom, prenom) "
//                        "VALUES (:id, :nom, :prenom)");
//          query.bindValue(":id", res);
//          query.bindValue(":nom", nom);
//          query.bindValue(":prenom", prenom);
//       qDebug()<<prenom;
//       if (query.exec()) {
//           test=true;
//         // got no error, proceed
//         qDebug() << "Yay!";
//       } else {
//         // got an error, deal with it
//         qDebug() << query.executedQuery();
//         qDebug() << query.lastError();
//       }


//    return test;
//          //return query.exec();
//}
//bool Etudiant::supprimer(int id)
//{
//    QSqlQuery query;
//    QString res=QString::number(id);
//    query.prepare("delete from etudiant where ID = id");
//    query.bindValue("id",res);
//    return query.exec();
//}


bool Event::supprimer(int id)
{
    cout<<id<<endl;
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete  from Event WHERE id=:id");
    qDebug()<<query.lastError();
    query.bindValue(0,id);


    return query.exec();
}



QSqlQueryModel * Event::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Event");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_event"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nombre_inv"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("budget"));

    return model;
}


bool Event::ajouter()
{
    QString id_string=QString::number(id);
    cout<<id<<endl;
    QString budget_string=QString::number(budget);
    QString nombre_inv_string=QString::number(nombre_inv);
    QSqlQuery query;
    query.prepare("INSERT INTO Event (id,type,date_event,nombre_inv,budget)"
                  "VALUES (:id,:type,:date_event,:nombre_inv,:budget)");
    query.bindValue(0,id_string);
    query.bindValue(1,type);
    query.bindValue(2,date);
    query.bindValue(3,nombre_inv_string);
    query.bindValue(4,budget_string);

   return query.exec();
}
bool Event::update()
{
    QString id_string=QString::number(id);
    cout<<id<<endl;


    QSqlQuery query;
    query.prepare("UPDATE EVENT SET type=:type,date_event=:date,nombre_inv=:nombre_inv,budget=:budget WHERE id=:id_string"
                  );
    query.bindValue(0,type);
    query.bindValue(1,date);
    query.bindValue(2,nombre_inv);
    query.bindValue(3,budget);
    query.bindValue(4,id_string);

    query.exec();

    return true;

}
