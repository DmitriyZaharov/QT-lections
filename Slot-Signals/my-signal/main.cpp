#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w1;
    QStringList headers;
    headers << "Subject: Hello World"
            << "From: qt-info@nokia.com";
    QString body = "This is a test.\r\n";
    Message message(body, headers);
    w1.setMessage(message);

    MainWindow w2;

    QObject::connect(&w1, w1.messageSent, &w2, w2.setMessage);
    QObject::connect(&w2, w2.messageSent, &w1, w1.setMessage);

    w1.show();
    w2.show();

    return a.exec();
}
