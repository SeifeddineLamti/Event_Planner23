#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    reminder_time = 0;
    popup = new Popup;

    systemTrayIcon = new QSystemTrayIcon(this);
    systemTrayIcon->setIcon(QIcon("C:/Users/a/Documents/crudddd/reminder.ico"));
    systemTrayIcon->show();
    ui->setupUi(this);

    ui->bStop->setDisabled(true);

    connect(ui->bStart, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(ui->bStop, SIGNAL(clicked()), this, SLOT(stopTimer()));
    connect(ui->bExit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(&timer_progress, SIGNAL(timeout()), this, SLOT(showProgress()));
    connect(&timer_reminder, SIGNAL(timeout()), this, SLOT(showReminder()));
    connect(popup, SIGNAL(closed()), this, SLOT(resetReminder()));
    connect(popup, SIGNAL(clicked()), this, SLOT(restartReminder()));


    connect(systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(systemTrayIconActivated(QSystemTrayIcon::ActivationReason)));


    setGeometry(QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()));

    setWindowTitle("Remind Me");
}

Window::~Window()
{
    delete ui;
}

void Window::resetReminder()
{
    ui->about->clear();
    ui->timeAfter->setTime(QTime(0,0,0));
    ui->timeAfter->setFocus();
}

void Window::restartReminder()
{
    ui->timeAfter->setFocus();
    showNormal();
}

void Window::startTimer()
{
    QTime after = ui->timeAfter->time();
    reminder_time = (after.hour()*3600 + after.minute()*60 + after.second()) * 1000;


    if(reminder_time < 1000)
    {

        QMessageBox::critical(this,
                              "Error",
                              "You cant set timer for less than 1s");
        return;
    }

    timer_reminder.start(reminder_time);
    ui->progressBar->setMaximum(reminder_time);
    ui->progressBar->setValue(reminder_time);
    showProgress();
    timer_progress.start(1000);


    ui->progressBar->setEnabled(true);
    ui->bStart->setDisabled(true);
    ui->bStop->setEnabled(true);


    close();
}

void Window::stopTimer()
{

    timer_progress.stop();
    timer_reminder.stop();
    ui->progressBar->reset();

    ui->progressBar->setEnabled(false);
    ui->bStart->setDisabled(false);
    ui->bStop->setEnabled(false);
}

void Window::showReminder()
{

    stopTimer();

    popup->showPopup(
                "Reminder",
                ui->about->toPlainText());
}

void Window::showProgress()
{

    ui->progressBar->setValue(timer_reminder.remainingTime());
}

void Window::systemTrayIconActivated(QSystemTrayIcon::ActivationReason)
{

    if(!isVisible())
        showNormal();

    else
        close();
}
