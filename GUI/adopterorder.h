#ifndef ADOPTERORDER_H
#define ADOPTERORDER_H
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QApplication>
#include <iostream>
#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include "payment.h"
#include "detailorder.h"
#include <QMessageBox>
#include <QPushButton>
#include "../DataBase/UserInfo/adopter.h"
namespace Ui {
class adopterorder;
}

class adopterorder : public QWidget
{
    Q_OBJECT

public:
    explicit adopterorder(QWidget *parent = 0, OrderDam* orderDam = nullptr);
    ~adopterorder();
    QVBoxLayout *pLayout = new QVBoxLayout();
    DetailOrder *order;
    OrderDam* myOrderDam;
    Adopter* myAdopter;

private:
    Ui::adopterorder *ui;
private slots:
    void adopterorderReceivesshow();
    void on_toolButton_home_clicked();
    void receiveRequestCreated();
//    void on_pushButton_clicked();

signals:
    void adopterorderShowmainwindow();
    void showpayment();

};



#endif // ADOPTERORDER_H
