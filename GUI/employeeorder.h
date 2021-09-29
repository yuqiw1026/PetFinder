#ifndef EMPLOYEEORDER_H
#define EMPLOYEEORDER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "detailorder.h"
#include "../Dam/orderdam.h"
#include "../DataBase/UserInfo/employee.h"
#include "../DataBase/searchengine.h"
namespace Ui {
class employeeorder;
}

class employeeorder : public QWidget
{
    Q_OBJECT

public:
    explicit employeeorder(QWidget *parent = 0, OrderDam* myOrderDam = nullptr, SearchEngine* searchEngine = nullptr);
    ~employeeorder();
    OrderDam* myOrderDam;
    QVBoxLayout *pLayout = new QVBoxLayout();
    Employee* myEmployee;
    SearchEngine* searchEngine;
private:
    Ui::employeeorder *ui;
private slots:
    void employeeorderReceivesshow();
    void on_toolButton_home_clicked();
    void receiverequest();

signals:
    void employeeorderShowmainwindow();

    void orderdetailshow();
    void requestCreatedEmp();
};

#endif // EMPLOYEEORDER_H
