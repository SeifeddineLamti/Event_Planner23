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
    ui->cin_sup->setModel(c.get_id());
    ui->cin_qr->setModel(c.get_id());

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
    QString sexe=ui->sexe->currentText();

    Client c(cin,nom,prenom,sexe,date_naissance,num_tel,adresse_email);
    bool test=c.ajouter();
    if (test) //si requete ajoutée
    {
        // refresh
        ui->tableView->setModel(c.afficher());
        ui->cin_sup->setModel(c.get_id());
        ui->cin_qr->setModel(c.get_id());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->cin->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->date->clear();
        ui->num_tel->clear();
        ui->ad->clear();
        ui->sexe->setCurrentIndex(0);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("ajout non effectué \n"
                                          "click cancel to exit."),QMessageBox::Cancel);

}


void MainWindow::on_supprimer_clicked()
{
    int cin=ui->cin_sup->currentText().toInt();
    bool test=c.supprimer(cin);
    if (test)
    {
        // refresh
        ui->tableView->setModel(c.afficher());
        ui->cin_sup->setModel(c.get_id());
        ui->cin_qr->setModel(c.get_id());
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
    QString sexe=ui->sexe->currentText();
    QString date_naissance=ui->date->text();
    int num_tel=ui->num_tel->text().toInt();
    QString adresse_email=ui->ad->text();




    Client c(cin,nom,prenom,sexe,date_naissance,num_tel,adresse_email);

    bool test=c.modifier();
        if(test)
        {

            ui->tableView->setModel(c.afficher());

            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("Modification avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->cin->clear();
            ui->nom->clear();
            ui->prenom->clear();
            ui->date->clear();
            ui->num_tel->clear();
            ui->ad->clear();
            ui->sexe->setCurrentIndex(0);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("Modification echoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tri_activated()
{
        if(ui->tri->currentText()=="")
          ui->tableView->setModel(c.afficher());
        else if(ui->tri->currentText()=="nom par ordre croissant")
            ui->tableView->setModel(c.tri_nom_croissant());
        else if(ui->tri->currentText()=="nom par ordre decroissant")
            ui->tableView->setModel(c.tri_nom_decroissant());
        else if(ui->tri->currentText()=="cin par ordre croissant")
            ui->tableView->setModel(c.tri_cin_croissant());
        else if(ui->tri->currentText()=="cin par ordre decroissant")
            ui->tableView->setModel(c.tri_cin_decroissant());
        else if(ui->tri->currentText()=="prenom par ordre croissant")
            ui->tableView->setModel(c.tri_nom_croissant());
        else if(ui->tri->currentText()=="prenom par ordre decroissant")
            ui->tableView->setModel(c.tri_nom_decroissant());


}

void MainWindow::on_cin_editingFinished()
{
    int cin=ui->cin->text().toInt();
        QSqlQuery query;
        query.prepare("select * from client where cin_cl=:cin");
        query.bindValue(":cin",cin);
        if (query.exec()){
            while(query.next())
            {ui->nom->setText(query.value(1).toString());
                ui->prenom->setText(query.value(2).toString());
                ui->date->setText(query.value(3).toString());
                ui->num_tel->setText(query.value(4).toString());
                ui->ad->setText(query.value(5).toString());
                ui->sexe->setCurrentText(query.value(6).toString());}
        }
}

void MainWindow::on_rechercher_clicked()
{
    QString cin=ui->cin_aff->text();
        ui->tableView->setModel(c.rech_cin(cin));
        ui->cin_aff->clear();
}

void MainWindow::on_cin_qr_currentIndexChanged()
{
        int rech=ui->cin_qr->currentText().toInt();
         QSqlQuery query;
         query.prepare("select * from client where cin_cl=:cin");
         query.bindValue(":cin",rech);

        QString cin,nom,prenom,date,num_tel,ad,sexe;

        if(query.exec())
        {
                while (query.next())
                {
                    cin=query.value(0).toString();
                    nom=query.value(1).toString();
                    prenom=query.value(2).toString();
                    date=query.value(3).toString();
                    num_tel=query.value(4).toString();
                    ad=query.value(5).toString();
                    sexe=query.value(6).toString();
                }
         }
        QString width="350",height="350";
        QString info="Cin: "+cin+", Nom: "+nom+", Prenom: "+prenom+", Date de naissance: "+date+",Num tel: "+num_tel+", Email: "+ad+",sexe:"+sexe+" ";
        QImage qr = QZXing::encodeData(info,QZXing::EncoderFormat_QR_CODE,QSize(width.toInt(), height.toInt()),QZXing::EncodeErrorCorrectionLevel_H);
        QGraphicsScene *qrcode = new QGraphicsScene(this);
        qrcode->addPixmap( QPixmap::fromImage(qr));
        ui->qr_gv->setScene(qrcode);
}

void MainWindow::on_aff_clicked()
{
    QSqlQuery qry;
        int cin=ui->cin->text().toInt();
        qry.prepare("select * from client where cin_cl=:cin");
        qry.bindValue(":cin",cin);
        if(qry.exec())
        {
            while(qry.next())
            {
                QPixmap photo;
                QString location=qry.value(7).toString();
                photo.load(location);
                ui->pic->setPixmap(photo);
                ui->pic->setScaledContents(true);
            }
        }
}

void MainWindow::on_photo_clicked()
{
    QString picpath=QFileDialog::getOpenFileName(this,tr("Open file"),"c://","JPG File(*.jpg);;PNG File(*.png)");
        int cin=ui->cin->text().toInt();
        QSqlQuery query;
        query.prepare("update client set pic=:picpath where cin_cl=:cin");
        query.bindValue(":picpath",picpath);
        query.bindValue(":cin",cin);
        query.exec();
}

void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from client where sexe='homme' ");
     int number1=model->rowCount(); //combien d personnes
     model->setQuery("select * from client where sexe='femme' ");
     int number2=model->rowCount();

     int total=number1+number2;
     QString a = QString("homme  "+QString::number((number1*100)/total,'f',2)+"%");
     QString b = QString("femme "+QString::number((number2*100)/total,'f',2)+"%");

     QPieSeries *series = new QPieSeries();
     series->append(a,number1); // te9sem charte graphique
     series->append(b,number2);

     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("sexes de nos clients");
             //chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();
}

void MainWindow::on_pdf_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView->model()->rowCount();
                const int columnCount =ui->tableView->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("client")
                        <<  "</head>\n"
                        "<body bgcolor=#FDFEFE link=#5000A0>\n"
                            "<h1>liste des clients</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // affichage titres des colonnes
                    out << "<thead><tr bgcolor=#F5B7B1>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // affichage du contenu
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView->isColumnHidden(column)) {
                                   QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("client.pdf");
        document->print(&printer);
}
