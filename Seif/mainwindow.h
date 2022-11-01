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

private:
    Ui::MainWindow *ui;
    Espaces E;
};

#endif // MAINWINDOW_H
