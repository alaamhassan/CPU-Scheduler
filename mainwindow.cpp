#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include <QMessageBox>
int processesNum;
int schedInd;
QString sched;
float quantum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("FCFS (First Come First Serve)");
    ui->comboBox->addItem("PSJF (Preemptive Shortest Job First)");
    ui->comboBox->addItem("NPSJF (Non-Preemptive Shortest Job First)");
    ui->comboBox->addItem("PP (Preemptive Priority)");
    ui->comboBox->addItem("NPP (Non-Preemptive Priority)");
    ui->comboBox->addItem("RR (Round Robin)");
    ui->lineEdit_2->setEnabled(false);
    ui->label_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_input_pushButton_clicked()
{
    processesNum = ui->lineEdit->text().toInt();
    schedInd = ui->comboBox->currentIndex();
    sched = ui->comboBox->currentText();
    int index = ui->comboBox->currentIndex();
    if (ui->lineEdit->text() == "") {
        QMessageBox::warning(this, "Invalid input", "You must enter number of processes");
    } else if(processesNum < 2 || processesNum > 10) {
        QMessageBox::warning(this, "Invalid input", "The number of processes must be an integer from 2 to 10");
    } else if (!(index <= 5 && index >= 0)) {
        QMessageBox::warning(this, "Invalid input", "You must choose a scheduler");
    } else if (ui->lineEdit_2->text() == "" && schedInd == 5) {
        QMessageBox::warning(this, "Invalid input", "You must enter a quantum value");
    }
    else {
        if (schedInd == 5) {
            quantum = ui->lineEdit_2->text().toFloat();
        }
        SecDialog secdialog;
        secdialog.setModal(true);
        secdialog.exec();
    }

}


void MainWindow::on_comboBox_activated(int index)
{
    if (index == 5) {
        ui->lineEdit_2->setEnabled(true);
        ui->label_2->setEnabled(true);
    } else {
        ui->lineEdit_2->setEnabled(false);
        ui->label_2->setEnabled(false);
    }
}

