#ifndef QSERIALCONNECTION_H
#define QSERIALCONNECTION_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


class QSerialConnection : public QObject {
    Q_OBJECT

public:
    explicit QSerialConnection(QObject *parent = nullptr);
    ~QSerialConnection();

    bool openPort(const QString &portName, int baudRate = QSerialPort::Baud115200);
    void closePort();
    bool isOpen() const;

    QList<QSerialPortInfo> availablePorts() const;
    bool writeData(const QByteArray &data);

signals:


private:
};

#endif // QSERIALCONNECTION_H
