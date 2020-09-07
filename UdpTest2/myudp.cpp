#include "myudp.h"


MyUDP::MyUDP()
{
    socket=new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,5555);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void MyUDP::SayHello(){
    QByteArray Data;
    Data.append("Hello from QT");
    socket->writeDatagram(Data,QHostAddress::LocalHost,5555);
}

void MyUDP::SendMessage(QString text)
{
    QByteArray Data;
    Data.append(text);
    socket->writeDatagram(Data,QHostAddress::LocalHost,5555);
    emit logMessage("sent: "+text);
}


void MyUDP::readyRead(){
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);

//    qDebug()<<"Message from "<<sender.toString();
    qDebug()<<"Port "<<senderPort;
    qDebug()<<"Message: "<<Buffer;
    emit logMessage("read: "+QString::fromUtf8(Buffer));
}
