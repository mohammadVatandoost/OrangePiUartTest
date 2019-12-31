#include "backend.h"

Backend::Backend()
{
    //    createTable();
        serial = new QSerialPort(this);
        serial->close();
        serial->setBaudRate(QSerialPort::Baud115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        // timer for connection check
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
        timer->start(1000);

        qDebug()<< "Start";
}


void Backend::recieveSerialPort()
{
    QByteArray data;
    data = serial->readAll();
    QString temp; temp.append(data);
    qDebug() << "recieveSerialPort :"<< temp;
    serial->write(data);
}

void Backend::timerSlot()
{
    qDebug()<< "timerSlot";
   if(QSerialPortInfo::availablePorts().size()>0) {
    if(!serial->isOpen()) {
        Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
                   serial->setPortName(port.portName());
                   qDebug() << " portName : " << port.portName();
        }
        if(serial->open(QIODevice::ReadWrite)) {
//          connectState = true;
          qDebug() << " conndected : ";
          connect(serial, SIGNAL(readyRead()), this, SLOT(recieveSerialPort()));
        } else {
//            connectState = false;
            qDebug() << "Not conndected : ";
            serial->close();
        }
    } else {

    }
   } else {
       serial->close();
//       connectState = false;qDebug() << "Disconndected : ";
   }

//   emit notifyInfoDataChanged();
}
