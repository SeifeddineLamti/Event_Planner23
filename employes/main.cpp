#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include "login.h"
#include "login.cpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    foreach (
                 const QSerialPortInfo &info, QSerialPortInfo::availablePorts()
                 ) {
            qDebug() << "Name        : " << info.portName();
            qDebug() << "Description : " << info.description();
            qDebug() << "Manufacturer: " << info.manufacturer();

            // Example use QSerialPort
            QSerialPort serial;
            serial.setPort(info);
            serial.write("q");

        }
    Connection c;
    //LOGIN l;
    bool test=c.createconnect();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  MainWindow w;
  w.show();
    return a.exec();
}
