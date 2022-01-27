#include "webclient.h"

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::connected, this, &Webclient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Webclient::readyRead);
}

void Webclient::printOutcome(QString message)
{
    outcome->clear();
    outcome->setText(message);
}

void Webclient::connected()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n").toLocal8Bit());
}

void Webclient::readyRead()
{
    printOutcome(m_socket->readAll());
    m_socket->disconnectFromHost();
}

void Webclient::on_startButton_clicked()
{
    m_hostname = hostname->text();
    m_socket->connectToHost(m_hostname, m_port);
    if (!m_socket->waitForConnected(5000))
    {
        printOutcome("Connection failed!");
    }

}
