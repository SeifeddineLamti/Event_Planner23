#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "client.h"
#include <QRegExpValidator>

#define valid_email "^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$"
#define valid_chaine "([A-Z][a-z]*)([\\s\\'-][A-Z][a-z]*)*"
#define valid_nombre "[0-9]+"
#define valid_date "^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-]\\d{4}$"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_ajouterr_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_tricroissant_clicked();
    void on_tridecroissant_clicked();

private:
    Ui::MainWindow *ui;
    Client c;
};
#endif // MAINWINDOW_H
