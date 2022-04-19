#include "secdialog.h"
#include "ui_secdialog.h"
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include<iomanip>
#include<climits>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<pair<float, int>, pair<int, float>> pi;
typedef pair<pair<int, float>, pair<int, float>> pi1;
typedef pair<int, float> g;

vector<int> ID(processesNum);
vector<float> arrivalTime(processesNum);
vector<float> burstTime(processesNum);
vector<int> priority(processesNum);
vector<float> wt(processesNum);
vector<pair<int,float>> wt_npsjf(processesNum);
vector<pair<int, pair<float, float>>> gantt_chart;
priority_queue< g, vector<g>, greater<g>> process_waiting_time;

QColor colors[10] = {Qt::red, Qt::darkYellow, Qt::yellow, Qt::green, Qt::darkGreen, Qt::cyan, Qt::blue, Qt::darkBlue, Qt::magenta, Qt::darkMagenta};
QGraphicsScene *scene;
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(sched);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ID.resize(processesNum);
    arrivalTime.resize(processesNum);
    burstTime.resize(processesNum);
    priority.resize(processesNum);
    wt.resize(processesNum);
    gantt_chart.clear();

    ui->gc_pushButton->setEnabled(false);
    ui->input_tableWidget->setRowCount(processesNum);
    ui->input_tableWidget->setColumnHidden(3, true);
    if (schedInd == 3 || schedInd == 4) {
        ui->input_tableWidget->setColumnHidden(3, false);
    }
    // Disable editing cells of the color column
    for (int i = 0; i<processesNum; i++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        ui->input_tableWidget->setItem(i,4,item);
    }
    // Disable editing cells of the ID column & autofilling it
    for (int i = 0; i<processesNum; i++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        item->setText(QString::number(i+1));
        ui->input_tableWidget->setItem(i,0,item);
        ID[i] = i+1;
    }
    //-----Set processes colors--------
    for (int i = 0; i < processesNum; i++) {
        ui->input_tableWidget->item(i, 4)->setBackground(QBrush(colors[i]));
    }
    //---------------------------------
}

SecDialog::~SecDialog()
{
    delete ui;
}
