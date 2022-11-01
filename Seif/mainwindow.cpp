#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "espaces.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
#include "connection.h"
#include <QSqlQuery>
#include <string>
using namespace std;
MainWindow::MainWindow(QWidget *ESPACES) :
    QMainWindow(ESPACES),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_espaces->setModel(E.afficher());

}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int ID_ESPACE=ui->le_ID->text().toInt();
    int CAPACITE=ui->le_capacite->text().toInt();
    QString NOM=ui->le_nom->text();
    QString TYPE=ui->le_type->text();
    QString LIEU=ui->le_lieu->text();
    QString DATE_LOCATION=ui->le_datelocation->text();
    int PRIX_LOCATION=ui->le_prixlocation->text().toInt();
    Espaces E(ID_ESPACE,CAPACITE,NOM,TYPE,LIEU,DATE_LOCATION,PRIX_LOCATION);
    bool test=false;
    test=E.ajouter();
    QMessageBox msgBox;
    if (test)
        msgBox.setText("ajout avec succes");
    else msgBox.setText("echec ajout");

ui->tab_espaces->setModel(E.afficher());
    msgBox.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    QString id=ui->le_ID->text();
    bool test;
    test=Espaces().Supprimer(id);

    if (test)
    {QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppresion avec succes"), QMessageBox::Cancel);
    ui->tab_espaces->setModel(E.afficher());}

    else     { QMessageBox::information(nullptr, QObject::tr("OK"),
                                       QObject::tr("echec suppression"), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_2_clicked()
{
    int ID_ESPACE=ui->le_ID->text().toInt();
    int CAPACITE=ui->le_capacite->text().toInt();
    QString x= ui->le_ID->text();
    QString NOM=ui->le_nom->text();
    QString TYPE=ui->le_type->text();
    QString LIEU=ui->le_lieu->text();
    QString DATE_LOCATION=ui->le_datelocation->text();
    int PRIX_LOCATION=ui->le_prixlocation->text().toInt();
    Espaces E(ID_ESPACE,CAPACITE,NOM,TYPE,LIEU,DATE_LOCATION,PRIX_LOCATION);
    bool test;
    test=E.modifier(x);
    QMessageBox msgBox;
    if (test)
        msgBox.setText("Modification avec succes");
    else msgBox.setText("echec modification");

ui->tab_espaces->setModel(E.afficher());
    msgBox.exec();

}

void MainWindow::on_le_ID_editingFinished()
{
    QString id= ui->le_ID->text();
    QSqlQuery q;
    q.prepare("SELECT * FROM ESPACES where id_espace = :x");
    q.bindValue(":x",id);
    q.exec();
    q.first();
    ui->le_type->setText(q.value(1).toString());
    ui->le_nom->setText(q.value(2).toString());
    ui->le_lieu->setText(q.value(3).toString());
    ui->le_capacite->setText(q.value(4).toString());
    ui->le_datelocation->setText(q.value(6).toString());
    ui->le_prixlocation->setText(q.value(5).toString());

}
