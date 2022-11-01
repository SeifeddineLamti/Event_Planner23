#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(c.afficher());

    //email validator
        QRegExp email(valid_email);
        //chaine validator
        QRegExp chaine(valid_chaine);
        //date validator
        QRegExp date(valid_date);
        //email validator
        QRegExp mail(valid_email);

        //champ cin
        QIntValidator *cin_valider =new QIntValidator(0,99999999,this);
        ui->cin->setValidator(cin_valider);
        ui->num_tel->setValidator(cin_valider);
        //champ nom et prenom
        QRegExpValidator *chaine_valider =new QRegExpValidator(chaine,this);
        ui->nom->setValidator(chaine_valider);
        ui->prenom->setValidator(chaine_valider);
        //champ date
        QRegExpValidator *date_valider =new QRegExpValidator(date,this);
        ui->date->setValidator(date_valider);
        //champ email
        QRegExpValidator *email_valider =new QRegExpValidator(mail,this);
        ui->ad->setValidator(email_valider);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouterr_clicked()
{
    int cin=ui->cin->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString date_naissance=ui->date->text();
    int num_tel=ui->num_tel->text().toInt();
    QString adresse_email=ui->ad->text();

    Client c(cin,nom,prenom,date_naissance,num_tel,adresse_email);
    bool test=c.ajouter();
    if (test) //si requete ajoutée
    {
        // refresh
        ui->tableView->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("ajout non effectué \n"
                                          "click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_supprimer_clicked()
{
    int cin=ui->cin->text().toInt();
    bool test=c.supprimer(cin);
    if (test)
    {
        // refresh
        ui->tableView->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("suppression non effectué \n"
                                          "click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_modifier_clicked()
{
    int cin=ui->cin->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString date_naissance=ui->date->text();
    int num_tel=ui->num_tel->text().toInt();
    QString adresse_email=ui->ad->text();


    Client c(cin,nom,prenom,date_naissance,num_tel,adresse_email);

    bool test=c.modifier();
        if(test)
        {

            ui->tableView->setModel(c.afficher());

            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Modification avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("Modification echoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tricroissant_clicked()
{
    ui->tableView->setModel(c.ordre_croissant());
}


void MainWindow::on_tridecroissant_clicked()
{
    ui->tableView->setModel(c.ordre_decroissant());
}
