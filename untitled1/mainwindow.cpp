#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->button_1, SIGNAL(clicked()), this, SLOT(CreateReport()));
    connect (ui->button_1, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Уведомление", "Отчёт сохраняется! Вы уверены в введённых данных?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        std::cout << "Всё идёт по плану!" << std::endl;
    }

}

void MainWindow::CreateReport()
{
    std::wcout << "Всё идёт по плану!" << std::endl;
    QString n_FIO = ui->label->text();
    QString n_birth = ui->label_2->text();
    QString n_SNILS = ui->label_4->text();
    QString n_POLIS = ui->label_3->text();
    QString n_simpt = ui->label_5->text();
    QString n_report = ui->label_6->text();
    QString FIO = ui->lineEdit->text();
    QString birth = ui->lineEdit_2->text();
    QString SNILS = ui->lineEdit_3->text();
    QString POLIS = ui->lineEdit_4->text();
    QString simpt = ui->lineEdit_5->text();
    QString report = ui->lineEdit_6->text();
    QFile Report("Отчёт.txt");
    if (Report.open(QIODevice::WriteOnly | QIODevice::Text))

    {
        QTextStream writeStream(&Report);
        writeStream << n_FIO << "\n";
        writeStream << FIO << "\n";
        writeStream << n_birth << "\n";
        writeStream << birth << "\n";
        writeStream << n_SNILS << "\n";
        writeStream << SNILS << "\n";
        writeStream << n_POLIS << "\n";
        writeStream << POLIS << "\n";
        writeStream << n_simpt << "\n";
        writeStream << simpt << "\n";
        writeStream << n_report << "\n";
        writeStream << report << "\n";
        Report.close();
    }
    Report.close();
}


