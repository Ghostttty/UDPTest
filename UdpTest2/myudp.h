#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>

class MyUDP: public QUdpSocket
{
    Q_OBJECT
public:
    MyUDP();
    void SayHello();
    void SendMessage(QString text);
signals:
    void logMessage(const QString &msg);
public slots:
    void readyRead();
private:
    QUdpSocket* socket;
};

#endif // MYUDP_H
