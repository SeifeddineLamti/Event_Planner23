#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "espaces.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *ESPACES = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_le_ID_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_calendar_clicked(const QDate &date);

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Espaces E;
};

#endif // MAINWINDOW_H
