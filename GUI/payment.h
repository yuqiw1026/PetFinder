#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "../DataBase/order.h"
#include "../Dam/orderdam.h"
#include <QMessageBox>
namespace Ui {
class payment;
}
using namespace std;

class payment : public QWidget
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = 0, string status = "", Order* myOrder = nullptr, OrderDam* myOrderDam = nullptr);
    ~payment();
    int deposit=1000;
    Order* myOrder;
    OrderDam* myOrderDam;
    void beingApproved();
    void on_pushButton_clicked();
    void completeOrder();
private slots:

    void paymentreceiveshow();

//    void on_toolButton_home_clicked();

//    void on_cancel_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_pay_clicked();

private:
    Ui::payment *ui;
signals:
void  paymentShowmainwindow();
void showadopterorder();
};

#endif // PAYMENT_H
