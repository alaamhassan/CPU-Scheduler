#ifndef SECDIALOG_H
#define SECDIALOG_H

//#include <vector>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
//using namespace std;
extern int processesNum;
extern int schedInd;
extern QString sched;
extern float quantum;
//extern vector<int> ID(processesNum);
//extern vector<int> arrivalTime(processesNum);
//extern vector<int> burstTime(processesNum);
//extern vector<int> priority(processesNum);

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();
private slots:
    void editOutputTable();

    void on_wt_pushButton_clicked();

    void on_gc_pushButton_clicked();

    void on_clear_pushButton_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
