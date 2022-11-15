#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QWidget>
#include <QTimer>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "popup.h"

namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_bStart_clicked();
    void startTimer();
    void stopTimer();
    void showReminder();
    void showProgress();
    void systemTrayIconActivated(QSystemTrayIcon::ActivationReason);
    void resetReminder();
    void restartReminder();

private:
    Ui::Window *ui;
    uint reminder_time;
    QTimer timer_progress;
    QTimer timer_reminder;
    QSystemTrayIcon *systemTrayIcon;
    Popup *popup;
};

#endif // WINDOW_H
