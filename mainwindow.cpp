#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "espaces.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
#include <string>
#include "connection.h"
#include <QSqlQuery>
#include <string>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QProcess>
#include <QVector>



using namespace std;
MainWindow::MainWindow(QWidget *ESPACES) :
    QMainWindow(ESPACES),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
       switch (ret) {
       case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
           break;
       case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
           break;
       case(-1):qDebug()<<"arduino is not available";
       }
 QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(incendie()));
    ui->tab_espaces->setModel(E.afficherEspaces());
    QChartView *chartview = new QChartView(Espaces().StatEspaces(),ui->widget);
    chartview->resize(500,400);

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
    int check1=0,check2=0;
    int i=0;
    int test8=0;
    string d=DATE_LOCATION.toStdString();
    if ((d[2]=='/')&&(d[5]=='/')&&(d.length()==10))
    {
        test8=1;

    }
    string n=NOM.toStdString();
    while((check1==0)&&(i<15)){
        if (isdigit(n[i]))
        check1=1;
        i++;

    }
    i=0;
  string n2=ui->le_type->text().toStdString();
    while((check2==0)&&(i<15)){
        if (isdigit(n2[i]))
        check2=1;
        i++;

    }
    if ((check1==0)&&(check2==0)&&(test8==1))
    test=E.ajouterEspaces();
    qDebug() << test;
    QMessageBox msgBox;
    if (test)
        msgBox.setText("ajout avec succes");
    else msgBox.setText("echec ajout");

ui->tab_espaces->setModel(E.afficherEspaces());
    msgBox.exec();

}

void MainWindow::on_SupprimerEspaces_clicked()
{
    QString id=ui->le_ID->text();
    bool test=false;

    test=Espaces().SupprimerEspaces(id);
QMessageBox msgBox;
    if (test)
    {msgBox.setText("Suppression avec succes");
     ui->tab_espaces->setModel(E.afficherEspaces());}
        else msgBox.setText("echec Suppression");
qDebug() << test;
msgBox.exec();

}

void MainWindow::on_AjouterEspaces_clicked()
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
    test=E.modifierEspaces(x);
    QMessageBox msgBox;
    if (test)
        msgBox.setText("Modification avec succes");
    else msgBox.setText("echec modification");

ui->tab_espaces->setModel(E.afficherEspaces());
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

void MainWindow::on_Recherche_clicked()
{
    QString x=ui->recherche->text();
    ui->tab_espaces->setModel(Espaces().RechercheEspaces(x));
}

void MainWindow::on_AnnulerRecherche_clicked()
{
    ui->tab_espaces->setModel(E.afficherEspaces());
}

void MainWindow::on_ConfimerTrie_clicked()
{
QString x=ui->Trie->currentText();
if (x=="Prix")
    ui->tab_espaces->setModel(Espaces().Trie_Prix());
else if (x=="Type")
    ui->tab_espaces->setModel(Espaces().Trie_Type());
else if (x=="Capacité")
    ui->tab_espaces->setModel(Espaces().Trie_Capacite());
}

void MainWindow::on_Exporter_clicked()
{
    QString pdf=ui->pdf->text();
    QPixmap pix(ui->widget->size());
    QPainter painter(&pix);
    ui->widget->render(&painter);
    painter.end();
    QPrinter printer(QPrinter::HighResolution);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    QString Emplacement = "D:\\ " + pdf + ".pdf";

    printer.setOutputFileName(Emplacement);

    painter.begin(&printer);
    double xscale = printer.pageRect().width() / double(pix.width());
    double yscale = printer.pageRect().height() / double(pix.height());
    double scale = qMin(xscale, yscale);
   painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2, // largeur
                    printer.paperRect().y() + printer.pageRect().height() / 2);
    painter.scale(scale, scale);
   painter.translate(-(ui->widget->width()) / 2, -(ui->widget->height()) / 2); // hauteur
    painter.drawPixmap(0, 0, pix);
    painter.end();
}

void MainWindow::on_Map_clicked()
{
    QString chemin="D:/build-MapTest-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/MapTest.exe";

    QProcess *x = new QProcess(this);
qDebug()<< chemin;
    x->start(chemin);
}


void MainWindow::on_calendar_clicked()
{
    QDate datee=ui->calendar->selectedDate();
        qDebug() << datee;
        QString d= datee.toString("dd/MM/yyyy");
        qDebug() << d;
        QSqlQuery query;
        query.prepare("SELECT id_espace,nom from espaces where date_location = :date");
        query.bindValue(":date",d);
        query.exec();
        QSqlQueryModel * model=new QSqlQueryModel();


              model->setQuery(query);
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));

              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
             ui->tableCalendrier1->setModel(model);




}

void MainWindow::on_tableCalendrier1_clicked(const QModelIndex &index)
{


   QString i=index.data().toString();
   QSqlQuery query;
   query.prepare("Select * from espaces where id_espace = :id");
   query.bindValue(":id",i);
   qDebug() << i;
   query.exec();
   QSqlQueryModel * model=new QSqlQueryModel();


         model->setQuery(query);
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Lieu"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Capacite"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix De Location"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date De Location"));


        ui->tableCalendrier2->setModel(model);


}







void MainWindow::incendie()
{

    data=a.read_from_arduino();
    bool test=false;
    qDebug() << data;
    if((data=="1")&&(test==false))
    {
        QMessageBox qbox;
        qbox.setText("DANGER!!!");
        qbox.setIcon(QMessageBox::Critical);
        qbox.exec();
        ui->tabWidget->setCurrentIndex(3);
        ui->stop->setEnabled(true);
        test=true;

    }
}



void MainWindow::on_stop_clicked()
{
    QString datee;
    QSqlQuery query;

    a.write_to_arduino("7");
    E.ajouterI(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm"));
    query.prepare("Select datei from hisincendie ");
    if(query.exec())
    {
        while(query.next())
        {
            datee=query.value(0).toString();

        }

    }
    qDebug()<<datee;
    QByteArray datef(datee.toUtf8(),16)    ;
    a.write_to_arduino(datef);
      ui->stop->setEnabled(false);

}


