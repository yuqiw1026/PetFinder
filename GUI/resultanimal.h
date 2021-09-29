#ifndef RESULTANIMAL_H
#define RESULTANIMAL_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <string>
#include <QMainWindow>
#include "../Dam/orderdam.h"
#include "../DataBase/animal.h"
#include "../DataBase/UserInfo/adopter.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>

namespace Ui {
class resultanimal;
}
using namespace std;
class ResultAnimal : public QWidget
{
    Q_OBJECT

public:
    explicit ResultAnimal(QWidget *parent = 0, OrderDam* orderDam = nullptr);
    OrderDam* myOrderDam;
    QSqlQuery* qryOrders;
    Animal* myAnimal;
    Adopter* adopter;
    string address;
    ~ResultAnimal();
    void updateDisplay(double dist);

private slots:
    void on_pushButton_clicked();
    void reltanmReceiveshow();
private:
    Ui::resultanimal *ui;
signals:
    void adoptrequestsent();
};

#endif // RESULTANIMAL_H
