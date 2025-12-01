#include "QSerialConnection.h"
#include <QDebug>

QSerialConnection::QSerialConnection(QObject *parent) : QObject(parent), serial(new QSerialPort(this)) {
    connect(serial, &QSerialPort::readyRead, this, &QSerialConnection::handleReadyRead);
}

QSerialConnection::~QSerialConnection() {

}

void QSerialConnection::handleReadyRead() {

}
