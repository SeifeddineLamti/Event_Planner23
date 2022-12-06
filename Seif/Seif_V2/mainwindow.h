#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "espaces.h"
#include <QMainWindow>
#include "arduino.h"

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

    void on_SupprimerEspaces_clicked();

    void on_AjouterEspaces_clicked();

    void on_le_ID_editingFinished();

    void on_Recherche_clicked();

    void on_AnnulerRecherche_clicked();

    void on_ConfimerTrie_clicked();

    void on_Exporter_clicked();

    void on_Map_clicked();



    void on_calendar_clicked();

    void on_tableCalendrier1_clicked(const QModelIndex &index);



    void incendie();



    void on_stop_clicked();





private:
    Ui::MainWindow *ui;
    Espaces E;
    Arduino a;
    QByteArray data;
};

#endif // MAINWINDOW_H
