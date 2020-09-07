#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myudp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_buttonSendMessage_clicked();
    void logMessage(QString msg);
private:
    Ui::MainWindow *ui;
    MyUDP client;
};

#endif // MAINWINDOW_H
