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
    void dataReceived(const QByteArray &data);
    void portError(const QString &errorMessage);
    void portOpened(const QString &portName);
    void portClosed();


private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *serial;
};

#endif // QSERIALCONNECTION_H
