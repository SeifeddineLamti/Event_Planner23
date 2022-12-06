#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQueryModel>
#include <QMainWindow>
#include <EMPLOYES.h>
#include "arduino.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_AJOUTER_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void update_label();

    void on_tableView_clicked(const QModelIndex &index);
    void  browse();
    void  sendMail();
    void   mailSent(QString );


    void on_sendboot_clicked();

    void on_pushButton_4_clicked();


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    EMPLOYES E,E1;
    QStringList files;
    arduino a;
    QByteArray data;


};

#endif // MAINWINDOW_H
