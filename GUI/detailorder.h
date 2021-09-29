#ifndef DETAILORDER_H
#define DETAILORDER_H

#include <QWidget>
#include <string>
#include "../DataBase/order.h"
#include "../Dam/orderdam.h"
namespace Ui {
class detailorder;
}
using namespace std;
class DetailOrder : public QWidget
{
    Q_OBJECT

public:
    explicit DetailOrder(QWidget *parent = 0, Order* myOrder = nullptr, OrderDam* myOrderDam = nullptr);
    ~DetailOrder();
   // bool approve = false;
    Order* myOrder;
    OrderDam* myOrderDam;

private slots:

    void on_reject_clicked();

    void on_approve_clicked();
    void ordertailReceivesshow();

private:
    Ui::detailorder *ui;
signals:

};

#endif // DETAILORDER_H
