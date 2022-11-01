#ifndef ESPACES_H
#define ESPACES_H
#include <QSqlQueryModel>
#include <QString>
class Espaces
{
public:
    Espaces();
    Espaces(int,int,QString,QString,QString,QString,float);
            int GetID_ESPACE() { return ID_ESPACE; }
            int getCAPACITE() { return CAPACITE; }
            QString GetNOM() { return NOM; }
            QString GetTYPE() { return TYPE; }
            QString GetLIEU() { return LIEU; }
            float GetPRIX_LOCATION() { return PRIX_LOCATION; }
            QString GetDATE_LOCATION() { return DATE_LOCATION; }


            void setID_ESPACE(int val) { ID_ESPACE = val; }
            void setCAPACITE(int val) { CAPACITE = val; }
            void SetNOM(QString val) { NOM = val; }
            void SetTYPE(QString val) { TYPE = val; }
            void SetLIEU(QString val) { LIEU = val; }
            void SetPRIX_LOCATION(float val) { PRIX_LOCATION = val; }
            void SetDATE_LOCATION(QString val) { DATE_LOCATION = val; }

            ;bool ajouter();
            QSqlQueryModel * afficher();
              bool Supprimer(QString x);
              bool modifier(QString x);

private:
    int ID_ESPACE,CAPACITE;
    QString TYPE,NOM,LIEU,DATE_LOCATION;
    int PRIX_LOCATION;

};

#endif // ESPACES_H
