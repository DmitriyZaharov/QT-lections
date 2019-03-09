#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "message.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void messageSent(const Message &message);

public slots:
    void setMessage(const Message &message);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Message thisMessage;
};

#endif // MAINWINDOW_H
