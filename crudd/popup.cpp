#include "popup.h"
#include "ui_popup.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
}

Popup::~Popup()
{
    delete ui;
}
void Popup::showPopup(QString title, QString description)
{
    // show the title in bold
    ui->title->setText(QString("<b>%1</b>").arg(title));
    // and the body in normal text
    ui->description->setText(description);

    // position the notification at desktop right bottom
    setGeometry(QStyle::alignedRect(
                    Qt::RightToLeft,
                    Qt::AlignBottom,
                    size(),
                    qApp->desktop()->availableGeometry()));
    show();
}

void Popup::closePopup()
{
    emit closed();
    close();
}

void Popup::mousePressEvent(QMouseEvent*)
{
    emit clicked();
    close();
}
