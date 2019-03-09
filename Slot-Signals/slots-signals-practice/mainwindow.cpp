#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    count(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_add_clicked()
{
    QPushButton *button = new QPushButton(this);
    button->setText("Button " + QString::number(count));
    count++;
    ui->layout_buttons->addWidget(button);

    connect(button, &QPushButton::clicked, [this, button](){
        ui->label_button_name->setText(button->text());
    });

}
