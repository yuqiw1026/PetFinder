#include "detailorder.h"
#include "ui_detailorder.h"

DetailOrder::DetailOrder(QWidget *parent, Order* myOrder, OrderDam* myOrderDam) :
    QWidget(parent),
    ui(new Ui::detailorder)
{
    ui->setupUi(this);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->myOrder = myOrder;
    this->myOrderDam = myOrderDam;
    ui->label_orderID->setText(QString::fromStdString( to_string( myOrder->getID())));
    ui->label_adopterID->setText(QString::fromStdString( to_string( myOrder->getAdopterID())));
    ui->label_animalID->setText(QString::fromStdString( to_string( myOrder->getAnimalID())));
}

DetailOrder::~DetailOrder()
{
    delete ui;
}


void DetailOrder::on_reject_clicked()
{
    this->hide();
    this->myOrderDam->rejectOrder(this->myOrder);
}

void DetailOrder::on_approve_clicked()
{
    this->hide();
    this->myOrderDam->approveOrder(this->myOrder);

}
void DetailOrder::ordertailReceivesshow(){
    this->show();
}
