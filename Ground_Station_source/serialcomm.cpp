#include "serialcomm.h"

SerialComm::SerialComm(QObject *parent) : QObject(parent)
{

}

void SerialComm::setup_serial(const QString &portName, int baudrate)
{
    // Serial port is configured and opened with the selected parameters:
    // Values selected in the GUI are passed:
    serial_portname = portName;
    serial_baudrate = baudrate;
    serial_timeout = 3000;

    serial->setPortName(serial_portname);
    serial->setBaudRate(baudrate);

    // Open selected port:
    serial->open(QIODevice::ReadWrite);

    // The rest of parameters are the default ones (no parity, 8 databits, 1 stopbit).
    status = 1;
}

QByteArray SerialComm::read_serial_message()
{
    //    //if(!serial_stop) {
    //    if (!serial->isOpen()) { // Try to open the selected port in Read/write mode.
    //        //emit error(tr("Can't open %1, error code %2")
    //        //.arg(m_portName).arg(serial.error()));
    //        return 0;
    //    }

    //    //if (serial.waitForReadyRead(serial_timeout)) {
    //        QByteArray responseData = serial->readAll();
    //        //            while (serial.waitForReadyRead(10))
    //        //                responseData += serial.readAll();

    //        const QString response = QString::fromUtf8(responseData);
    //        emit this->response(response);
    //    //}
    //    //}

    //uint8_t          cp;
    //mavlink_status_t status;
    //uint8_t          msgReceived = false;

    // --------------------------------------------------------------------------
    //   READ FROM PORT
    // --------------------------------------------------------------------------

    // this function locks the port during read
    QByteArray responseData = serial->read(serial->bytesAvailable());
    return responseData;

    //const QString response = QString::fromUtf8(responseData);
    //emit this->response(response, responseData);
    //mavlink_message_t message;

    //msgReceived = mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
}

void SerialComm::write_serial_message(uint8_t* data, uint16_t bytes)
{
    // Change format of data in accordance to the write function:
    const char *serial_data = reinterpret_cast<char*>(data);

    qint64 bytes_written = serial->write(serial_data, bytes);
}

void SerialComm::stop_serial()
{
    // Close current serial port:
    serial->close();
    emit this->finished();
}
