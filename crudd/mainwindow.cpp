#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QMessageBox>
#include <QIntValidator>
#include "connection.h"
#include <QSqlQueryModel>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tableView->setModel(E.supprimer(id));
    ui->table_event->setModel(E.afficher());
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->table_event->setModel(E.afficher());
    QPixmap pix("C:/Users/a/Desktop/c++/Capture_logo.PNG");
    ui->label_2->setPixmap(pix.scaled(240,240,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}




//void MainWindow::on_ajouterclicked()
//{
//    int id=ui->le_id->text().toInt();
//    QString nom=ui->le_nom->text();
//    QString prenom=ui->le_prenom->text();
//    Etudiant E(id,nom,prenom);
//}



void MainWindow::on_pb_ajouter_clicked()
{   bool t=true;
    int id=ui->le_id->text().toInt();
    QString type=ui->le_type->text();
    QString date=ui->le_date->text();
    int nombre_inv=ui->le_nombre->text().toUInt();
    int budget=ui->le_budget->text().toUInt();
    if(id==0||type.isEmpty()||date.isEmpty()||type.isEmpty()||nombre_inv==0||budget==0)
    {
        t=false;
    }
    Event E(id,type,date,nombre_inv,budget);
    bool test=E.ajouter();
    if(test && t)
    {
        ui->table_event->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectue\n"
                                                                       "click cancel to cancel"),QMessageBox::Cancel);
    }

    else if (t==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("verifier vos donnes\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);}

    else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("ajouter non effectue\n"
                                          "click cancel to exit"),QMessageBox::Cancel);}
}



//void MainWindow::on_supprimer_clicked()
//{
//    int id =ui->lineEdit->text().toInt();
//    bool test=Etmp.supprimer(id);
//    if(test)
//    {
//        ui->tableView->setModel(Etmp.afficher());
//        QMessageBox::information(nullptr,QObject::tr("ok"
//                                  "Supression effectue"),
//                                 "Click cancel tp exit",QMessageBox::Cancel);
//    }
//    else
//    {
//        ui->tableView->setModel(Etmp.afficher());
//        QMessageBox::critical(nullptr,QObject::tr("Not OK"
//                                  "Supression non effectue"),
//                                 "Click cancel tp exit",QMessageBox::Cancel);
//    }
//}



//void MainWindow::on_supprimer_clicked()
//{
//    Etudiant E1; E1.setid(ui->le_supprimer->text().toInt());
//    bool test=E.supprimer(E1.getid());

//    QMessageBox msgBox;
//    if(test)
//      {
//        msgBox.setText("Supression avec succes");

//        //refresh

//        ui->tableView->setModel(E.afficher());
//      }
//    else
//        msgBox.setText("Echec de suppression");
//        msgBox.exec();
//}

//void MainWindow::on_pb_supprimer_clicked()
//{
//    int id=ui->le_id->text().toInt();
//    bool test=E.supprimer(id);

//    QMessageBox msgBox;
//    if(test)
//      {
//        msgBox.setText("Supression avec succes");

//        //refresh

//        ui->table_event->setModel(E.afficher());
//      }
//    else
//        msgBox.setText("Echec de suppression");
//        msgBox.exec();
//}

//void MainWindow::on_pushButton_edit_clicked()
//{
//    int id=ui->le_id->text().toInt();
//    QString type=ui->le_type->text();
//    QString date=ui->le_date->text();
//    int nombre_inv=ui->le_nombre->text().toUInt();
//    int budget=ui->le_budget->text().toUInt();
//    Event E(id,type,date,nombre_inv,budget);
//    bool test=E.update();
//    if(test)
//    {
//        ui->table_event->setModel(E.afficher());
//        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectue\n"
//                                                                       "click cancel to cancel"),QMessageBox::Cancel);
//    }
//    else
//    {QMessageBox::critical(nullptr,QObject::tr("not ok"),
//                              QObject::tr("modifiaction non effectue\n"
//                                          "click cancel to exit"),QMessageBox::Cancel);}
//}

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->le_id_2->text().toInt();
    bool test=E.supprimer(id);

    QMessageBox msgBox;
    if(test)
      {
        msgBox.setText("Supression avec succes");

        //refresh

        ui->table_event->setModel(E.afficher());
      }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_pushButton_10_clicked()
{
    bool t=true;
    int id=ui->le_id->text().toInt();
    QString type=ui->le_type->text();
    QString date=ui->le_date->text();
    int nombre_inv=ui->le_nombre->text().toUInt();
    int budget=ui->le_budget->text().toUInt();
    if(id==0||type.isEmpty()||date.isEmpty()||type.isEmpty()||nombre_inv==0||budget==0)
    {
        t=false;
    }

    Event E(id,type,date,nombre_inv,budget);
    bool test=E.update();
    if(test && t)
    {
        ui->table_event->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectue\n"
                                                                       "click cancel to cancel"),QMessageBox::Cancel);
    }

    else if (t==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("verifier vos donnes\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);}

    else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("modification non effectue\n"
                                          "click cancel to exit"),QMessageBox::Cancel);}
}
