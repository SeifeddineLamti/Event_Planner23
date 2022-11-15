#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QMessageBox>
#include <QIntValidator>
#include "connection.h"
#include <QSqlQueryModel>
#include <QPixmap>
#include <chrono>
#include <thread>
#include <windows.h>
#include <QDialog>
#include <iostream>
#include <ostream>
#include <QDebug>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QDate>




using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tableView->setModel(E.supprimer(id));
    ui->table_event->setModel(E.afficher());
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->table_event->setModel(E.afficher());
//    ui->l_ident->setText("verfier votre ID");
    QPixmap pix("C:/Users/a/Desktop/c++/Capture_logo.PNG");
    ui->label_2->setPixmap(pix.scaled(260,260,Qt::KeepAspectRatio));

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
    QString type=ui->comboBox->currentText();
   // QString date=ui->le_date->text();
    int nombre_inv=ui->le_nombre->text().toUInt();
    int budget=ui->le_budget->text().toUInt();
    QDate date=ui->dateedit->date();
//    QString date_string = datee.toString();
//    cout<<datee<<endl ;
//    cout<<date_string<<endl;


    if(id==0||type.isEmpty()||type.isEmpty()||nombre_inv==0||budget==0)
    {
        //ui->l_id->setText("verfier ID");
        t=false;
    }

    Event E(id,type,date,nombre_inv,budget);
    bool test=E.ajouter();
    if(test && t)
    {

        ui->table_event->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajouter effectue\n"
                                                                       "ok cancel to cancel"),QMessageBox::Ok);
    }

    else if (t==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("verifier vos donnes dabord\n"
                                                  "ok cancel to exit"),QMessageBox::Ok);}

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

//void MainWindow::on_pushButton_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(1);
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(2);
//}

//void MainWindow::on_pushButton_4_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWindow::on_pushButton_5_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(2);
//}

//void MainWindow::on_pushButton_7_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(0);
//}

//void MainWindow::on_pushButton_8_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(1);
//}

//void MainWindow::on_pushButton_3_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(3);
//}

//void MainWindow::on_pushButton_6_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(3);
//}

//void MainWindow::on_pushButton_9_clicked()
//{
//    ui->stackedWidget->setCurrentIndex(3);
//}



//void MainWindow::on_pushButton_10_clicked()
//{
//    bool t=true;
//    int id=ui->le_id->text().toInt();
//    QString type=ui->comboBox->currentText();
//    //QString type=ui->le_type->text();
//    QString date=ui->le_date->text();
//    int nombre_inv=ui->le_nombre->text().toUInt();
//    int budget=ui->le_budget->text().toUInt();
//    if(id==0||type.isEmpty()||date.isEmpty()||type.isEmpty()||nombre_inv==0||budget==0)
//    {
//        t=false;
//    }

//    Event E(id,type,date,nombre_inv,budget);
//    bool test=E.update();
//    if(test && t)
//    {
//        ui->table_event->setModel(E.afficher());
//        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectue\n"
//                                                                       "click cancel to cancel"),QMessageBox::Cancel);
//    }

//    else if (t==false)
//    {
//        QMessageBox::critical(nullptr,QObject::tr("not ok"),
//                                      QObject::tr("verifier vos donnes \n"
//                                                  "click cancel to exit"),QMessageBox::Cancel);}

//    else
//    {QMessageBox::critical(nullptr,QObject::tr("not ok"),
//                              QObject::tr("modification non effectue\n"
//                                          "click cancel to exit"),QMessageBox::Cancel);}
//}






void MainWindow::on_pb_verifier_clicked()
{
    int id=ui->le_id->text().toInt();
//    QString type=ui->le_type->text();

    QString type=ui->comboBox->currentText();
    //QString date=ui->le_date->text();
    int nombre_inv=ui->le_nombre->text().toUInt();
    int budget=ui->le_budget->text().toUInt();


    if(id==0)
    {
        ui->l_id->setText("verfier ID");
    }
    if(id!=0)
    {
        ui->l_id->setText("  ");
    }
    if(nombre_inv==0)
    {
        ui->l_nombre->setText("verifier le nombre");
    }
    if(budget==0)
    {
        ui->l_budget->setText("verifeir le budget ");
    }
    if(nombre_inv!=0)
    {
        ui->l_nombre->setText("  ");
    }
    if(budget!=0)
    {
        ui->l_budget->setText("  ");
    }
    if (id!=0&&nombre_inv!=0&&budget!=0)
    {
        {QMessageBox::information(nullptr,QObject::tr("not ok"),
                                  QObject::tr("verification termine\n"
                                              "click ok pour continuer"),QMessageBox::Ok);}
    }
}

void MainWindow::on_pb_modifier_clicked()
{
    bool t=true;
    int id=ui->le_id->text().toInt();
    QString type=ui->comboBox->currentText();
    //QString type=ui->le_type->text();
    QDate date=ui->dateedit->date();

    int nombre_inv=ui->le_nombre->text().toUInt();
    int budget=ui->le_budget->text().toUInt();
    if(id==0||type.isEmpty()||type.isEmpty()||nombre_inv==0||budget==0)
    {
        t=false;
    }

    Event E(id,type,date,nombre_inv,budget);
    bool test=E.update();
    if(test && t)
    {
        ui->table_event->setModel(E.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modification effectue\n"
                                                                       "click ok pour continuer"),QMessageBox::Ok);
    }

    else if (t==false)
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("verifier vos donnes \n"
                                                  "click cancel to exit"),QMessageBox::Cancel);}

    else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("modification non effectue\n"
                                          "click cancel to exit"),QMessageBox::Cancel);}
}

void MainWindow::on_pb_chercher_clicked()
{

    int id=ui->le_chercher->text().toInt();
    QString date=ui->le_chercher->text();
    QString type=ui->le_chercher->text();


    ui->table_event->setModel(E.chercher(id,date,type));
    if(id==0&&date.length()==0&&type.length()==0)
        E.afficher();
}

void MainWindow::on_pb_chercher_2_clicked()
{
    QString recherche = ui->le_chercher->text();
        if(recherche.length()!=0)

         {
            ui->table_event->setModel(E.cherchertype(recherche));

         }
        else
        {
           ui->table_event->setModel(E.afficher());
        }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->table_event->setModel(E.trie_nbr());
}

void MainWindow::on_pb_trie_id_clicked()
{
//    QString recherche = ui->le_chercher->text();
//    if(recherche.length()!=0)
//    {
       ui->table_event->setModel(E.trie_id());
//    }
//    else
//    {
//        ui->table_event->setModel(E.afficher());
//    }
}

//void MainWindow::on_pushButton_clicked()
//{

//        QSqlQuery query,query1,query2,query3;
//            qreal c1=0 ,sum=0,c2=0,c3=0;
//            query.prepare("SELECT * FROM event") ;
//            query.exec();
//            while(query.next())
//            {
//                    sum++ ;
//            }

//            query1.prepare("SELECT * FROM event where age >25 and age<35") ;
//            query1.exec();
//            while(query1.next())
//            {
//                    c1++ ;
//            }

//            query2.prepare("SELECT * FROM event where age >35 and age<45 ") ;
//            query2.exec();
//            while(query2.next())
//            {
//                    c2++ ;
//            }

//            query3.prepare("SELECT * FROM event where age >45") ;
//            query3.exec();
//            while(query3.next())
//            {
//                    c3++ ;
//            }

//        qreal d1,d2,d3;
//        d1=(c1/sum)*100;
//        d2=(c1/sum)*100;
//        d3=(c1/sum)*100;
//            QBarSet *set1 = new QBarSet("age>25");
//            QBarSet *set2 = new QBarSet("age>35");
//            QBarSet *set3 = new QBarSet("age>45");


//            // Assign values for each bar
//             *set1 << d1 ;
//             *set2 << d2 ;
//             *set3 << d3 ;


//            // Add all sets of data to the chart as a whole
//            // 1. Bar Chart
//            QBarSeries *series = new QBarSeries();

//            // 2. Stacked bar chart
//            // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();

//            series->append(set1);
//            series->append(set2);
//            series->append(set3);


//            // Used to define the bar chart to display, title
//            // legend,
//            QChart *chart = new QChart();

//            // Add the chart
//            chart->addSeries(series);

//            // Set title
//            chart->setTitle("STATISTIQUE");

//            // Define starting animation
//            // NoAnimation, GridAxisAnimations, SeriesAnimations
//            chart->setAnimationOptions(QChart::SeriesAnimations);

//            // Holds the category titles
//            QStringList categories;
//            categories << "stats";

//            // Adds categories to the axes
//            QBarCategoryAxis *axis = new QBarCategoryAxis();
//            axis->append(categories);
//            chart->addAxis(axis, Qt::AlignBottom);
//            series->attachAxis(axis);
//            chart->createDefaultAxes();


//            // 2. Stacked Bar chart

//            // Define where the legend is displayed
//            chart->legend()->setVisible(true);
//            chart->legend()->setAlignment(Qt::AlignBottom);


//            // Used to display the chart
//            QChartView *chartView = new QChartView(chart);
//            chartView->setRenderHint(QPainter::Antialiasing);

//             chartView->setMinimumSize(1021,601);
//            chartView->setParent(ui->tab_e);

//            // Used to change the palette
//            QPalette pal = qApp->palette();


//            // Apply palette changes to the application
//            qApp->setPalette(pal);

//}

void MainWindow::on_pdf_clicked()
{
   E.pdfprinter();
}

void MainWindow::on_pushButton_clicked()
{
   s = new stat_combo();
   s->setWindowTitle("statistique ComboBox");
   s->choix_pie();
   s->choix_bar();
   s->show();
}





void MainWindow::on_themebox_activated(const QString &arg1)
{
    if (ui->themebox->currentIndex()==1)
    {
        ui->khalfeya->setStyleSheet("background-color:black;");
        ui->le_id->setStyleSheet("QLineEdit{border:2px,solid white;border-radius:10px;color:black;padding-left :10px;padding-right:20px;background-color: rgb(255, 255, 255);}"
                                 "QLineEdit:hover{border:3px solid black;}"
                                 "QLineEdit{border:1.5px solid rgb(115, 115, 115);background-color: white;}"
                                 "QLineEdit:focus{border: 3px solid black;}");
        ui->le_budget->setStyleSheet("QLineEdit{border:2px,solid white;border-radius:10px;color:black;padding-left :10px;padding-right:20px;background-color: rgb(255, 255, 255);}"
                                     "QLineEdit:hover{border:3px solid black;}"
                                     "QLineEdit{border:1.5px solid rgb(115, 115, 115);background-color: white;}"
                                     "QLineEdit:focus{border: 3px solid black;}");
        ui->le_nombre->setStyleSheet("QLineEdit{border:2px,solid white;border-radius:10px;color:black;padding-left :10px;padding-right:20px;background-color: rgb(255, 255, 255);}"
                                     "QLineEdit:hover{border:3px solid black;}"
                                     "QLineEdit{border:1.5px solid rgb(115, 115, 115);background-color: white;}"
                                     "QLineEdit:focus{border: 3px solid black;}");
        ui->pb_ajouter->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                      "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                      "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_modifier->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                       "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                       "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_supprimer->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                        "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                        "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                        "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                        "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_verifier->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                       "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                       "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_chercher->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                       "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                       "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_chercher_2->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                         "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                         "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                         "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                         "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_reminder->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                         "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                         "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pb_trie_id->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                         "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                         "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");
        ui->pdf->setStyleSheet("QPushButton{background-color: rgb(91, 91, 91);color:rgb(182, 182, 182);border-radius:15px;border-bottom:3px solid black;}"
                                         "QPushButton:enabled{background-color: rgb(91, 91, 91);color: ;}"
                                         "QPushButton:pressed{background-color: rgb(52, 52, 52);color: black;}");

        ui->groupBox->setStyleSheet("background-color:rgb(34,34,34);border-radius:10px;border:1px solid black;");
        ui->groupBox_2->setStyleSheet("background-color:rgb(34,34,34);border-radius:10px;border:1px solid black;");
        ui->groupBox_3->setStyleSheet("background-color:rgb(34,34,34);border-radius:10px;border:1px solid black;");
       // ui->groupBox_4->setStyleSheet("background-color:rgb(50,50,50);border-radius:10px;border:1px solid black;");
       //ui->label_2->setStyleSheet("background-color:rgb(50,50,50);border-radius:10px;border:1px solid black;");
    }
    if (ui->themebox->currentIndex()==0)
    {
        ui->khalfeya->setStyleSheet("background-color:transparent;");
        ui->groupBox->setStyleSheet("background-color:rgb(248, 246, 240);border-radius:10px;");
        ui->groupBox_2->setStyleSheet("background-color:rgb(248, 246, 240);border-radius:10px;");
        ui->groupBox_3->setStyleSheet("background-color:rgb(248, 246, 240);border-radius:10px;");

        ui->pb_ajouter->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_modifier->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_chercher->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_supprimer->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pushButton_2->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_chercher_2->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_reminder->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_trie_id->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pdf->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
        ui->pb_verifier->setStyleSheet("QPushButton{background-color: rgb(93, 93, 93);color:black ;border-radius:10px;border-bottom:3px solid #aaaaaa;}"
                                      "QPushButton:enabled{background-color: rgb(230, 180, 200)  ; border-color:black;}"
                                      "QPushButton:pressed{background-color: rgb(230, 150, 180)   ;color:  black   ;}");
    }


}

void MainWindow::on_langue_activated(const QString &arg1)
{
    if(ui->langue->currentIndex()==1)
    {
        ui->le_id->setPlaceholderText("  Identify");
        ui->le_budget->setPlaceholderText("  Budget of event");
        ui->le_nombre->setPlaceholderText("  Number of invited people");
        ui->pb_ajouter->setText("Add");
        ui->pb_modifier->setText("Modify");
        ui->pb_supprimer->setText("Delete");
        ui->pb_chercher->setText("Scan");
        ui->pushButton_2->setText("Sort by NB_inv");
        ui->pushButton->setText("Statistic");
        ui->pb_verifier->setText("Verify");
        ui->pb_chercher_2->setText("Display");
        ui->pb_trie_id->setText("Sort by ID");
    }
    if(ui->langue->currentIndex()==0)
    {
        ui->le_id->setPlaceholderText("  Identifiant");
        ui->le_budget->setPlaceholderText("  Budget");
        ui->le_nombre->setPlaceholderText("  Nombre des invites");
        ui->pb_ajouter->setText("Ajouter");
        ui->pb_modifier->setText("Modifier");
        ui->pb_supprimer->setText("Supprimer");
        ui->pb_chercher->setText("Recherche");
        ui->pushButton_2->setText("Tri par NB_vg");
        ui->pushButton->setText("Statistique");
        ui->pb_verifier->setText("Verifier");
        ui->pb_chercher_2->setText("Affciher");
        ui->pb_trie_id->setText("Trie par ID");

    }
}




void MainWindow::on_pushButton_3_clicked()
{
    p = new Window();
    p->show();
}


void MainWindow::on_pb_reminder_clicked()
{
    p = new Window();
    p->show();
}
