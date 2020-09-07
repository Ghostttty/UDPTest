#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myudp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&client,SIGNAL(logMessage(QString)),this,SLOT(logMessage(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    client.SayHello();
}

void MainWindow::on_buttonSendMessage_clicked()
{
    client.SendMessage(ui->messageLine->text());
    ui->messageLine->clear();
}

void MainWindow::logMessage(QString msg)
{
    ui->logEditor->appendPlainText(msg + QLatin1Char('\n'));
    ui->logEditor->update();

}
