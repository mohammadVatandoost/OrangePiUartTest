#ifndef BACKEND_H
#define BACKEND_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QDebug>
#include <iostream>

using namespace std;

class Backend: public QObject
{
    Q_OBJECT
public:
    Backend();
    QSerialPort *serial;
    QString come_port;
    QTimer *timer;

private slots:
    void recieveSerialPort();
    void timerSlot();
};

#endif // BACKEND_H
