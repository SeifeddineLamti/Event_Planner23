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
    ui->tab_espaces->setModel(E.afficher());
    QChartView *chartview = new QChartView(Espaces().Stat(),ui->widget);
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
    test=E.ajouter();
    qDebug() << test;
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
    bool test=false;

    test=Espaces().Supprimer(id);
QMessageBox msgBox;
    if (test)
    {msgBox.setText("Suppression avec succes");
     ui->tab_espaces->setModel(E.afficher());}
        else msgBox.setText("echec Suppression");
qDebug() << test;
msgBox.exec();

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

void MainWindow::on_pushButton_clicked()
{
    QString x=ui->recherche->text();
    ui->tab_espaces->setModel(Espaces().Recherche(x));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tab_espaces->setModel(E.afficher());
}

void MainWindow::on_pushButton_5_clicked()
{
QString x=ui->comboBox->currentText();
if (x=="Prix")
    ui->tab_espaces->setModel(Espaces().Trie_Prix());
else if (x=="Type")
    ui->tab_espaces->setModel(Espaces().Trie_Type());
else if (x=="Capacité")
    ui->tab_espaces->setModel(Espaces().Trie_Capacite());
}

void MainWindow::on_pushButton_6_clicked()
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

void MainWindow::on_pushButton_7_clicked()
{
    QString chemin="D:/build-MapTest-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/MapTest.exe";

    QProcess *x = new QProcess(this);
qDebug()<< chemin;
    x->start(chemin);
}


void MainWindow::on_calendar_clicked(const QDate &date)
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
             ui->tableView->setModel(model);




}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
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


        ui->tableView_2->setModel(model);


}
