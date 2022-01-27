#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include <QTcpSocket>
#include <QAbstractSocket>
#include "ui_webclient.h"



class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT
public:
    explicit Webclient(QWidget *parent = nullptr);


    void connected();
    void readyRead();


private slots:
    void on_startButton_clicked();
    void printOutcome(QString message);

private:
    QTcpSocket *m_socket;
    QString m_hostname;

    unsigned short m_port = 80;

};

#endif // WEBCLIENT_H
