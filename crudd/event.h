#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <QSqlQueryModel>
class Event
{
public:
    Event(){};
    Event(int,QString,QString,int,int);
    int getid();
    QString gettype();
    QString getdate();
    int getnombre_inv();
    int getbudget();
    void setid(int);
    void settype(QString);
    void setdate(QString);
    void setnombre_inv(int);
    void setbudget(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool update();



private:
    int id,nombre_inv,budget;
    QString type,date;


};

#endif // EVENT_H
