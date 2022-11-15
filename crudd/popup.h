#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QDesktopWidget>
#include <QMouseEvent>

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();
    void showPopup(QString title, QString description);
    void mousePressEvent(QMouseEvent*);

private:
    Ui::Popup *ui;
signals:
    void closed();
    void clicked();
private slots:
    void closePopup();
};

#endif // POPUP_H
