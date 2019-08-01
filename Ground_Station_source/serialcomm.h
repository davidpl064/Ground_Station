#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>

#include <QThread>
#include <QMutex>
#include <QSerialPort>
#include <QIODevice>

#include <QDebug>

// MAVLINK messaging protocol:
#include <MAVlink/common/mavlink.h>

class SerialComm : public QObject
{
    Q_OBJECT
public:
    int  status;
    bool debug;

    explicit SerialComm(QObject *parent = nullptr);
    void write_serial_message(uint8_t* data, uint16_t bytes);
    void stop_serial();
signals:
    void response(const QString &s, QByteArray responseData);
    void finished();

public slots:
    void setup_serial(const QString &portName, int baudrate);
    QByteArray read_serial_message();

private:
    QSerialPort *serial = new QSerialPort(this);
    QString serial_portname;
    int serial_baudrate;
    int serial_timeout;
    QMutex serial_mutex;

    int  fd;
    mavlink_status_t lastStatus;
};

#endif // SERIALCOMM_H
