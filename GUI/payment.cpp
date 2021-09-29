#include "payment.h"
#include "ui_payment.h"

payment::payment(QWidget *parent, string status, Order* myOrder, OrderDam* myOrderDam) :
    QWidget(parent),
    ui(new Ui::payment)
{
    ui->setupUi(this);

    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_6->setVisible(false);
    ui->lineEdit_balance->setVisible(false);
    ui->lineEdit_csv->setVisible(false);
    ui->lineEdit_cardNum->setVisible(false);
    ui->lineEdit_expireDate->setVisible(false);
    ui->pushButton_pay->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_delete->setVisible(false);
    this->ui->lineEdit_balance->setValidator(new QRegExpValidator(QRegExp("^(([0-9]+\\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\\.[0-9]+)|([0-9]*[1-9][0-9]*))$")));
    if(status == "Approved"){
        beingApproved();
    }else if(status == "Rejected"){
        ui->label_5->setText("Sorry, your request was rejected\n Please try another pet");
        ui->pushButton_delete->setVisible(true);
    }else if(status == "Waiting For Approval"){
        ui->label_5->setText("Thank you for your patience\n We are working on this as soon as we can");
    }else if(status == "Completed"){
        ui->label_5->setText("Congraduation! You just finshed this adoption!");
    }
    this->myOrder = myOrder;
    this->myOrderDam = myOrderDam;
}

payment::~payment()
{
    delete ui;
}

void payment::on_pushButton_clicked()
{
    this->hide();
    if(deposit>=150){
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Pay for adoption fee successfully"),QString("You adopt the animal successfully! Please wait for your pet delivery"));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
        //emit showadopterorder();
    }else{

        QMessageBox *m_box= new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Your deposit is not enought. Please check your account."));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
        //emit showadopterorder();
    }
}
void payment::paymentreceiveshow(){
    this->show();
}

void payment::beingApproved()
{
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(true);
    ui->lineEdit_balance->setVisible(true);
    ui->lineEdit_csv->setVisible(true);
    ui->lineEdit_cardNum->setVisible(true);
    ui->lineEdit_expireDate->setVisible(true);
    ui->pushButton_pay->setVisible(true);
    ui->pushButton_cancel->setVisible(true);
}

void payment::on_pushButton_delete_clicked()
{
    myOrderDam->deleteOneOrder(this->myOrder);
    this->hide();
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Processing"),QString("Deleted Successfully"));
    QTimer::singleShot(1000,m_box,SLOT(accept()));
    m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
    m_box->exec();

}

void payment::on_pushButton_pay_clicked()
{
    string cardNum = ui->lineEdit_cardNum->text().toStdString();
    string csv = ui->lineEdit_csv->text().toStdString();
    string expireDay = ui->lineEdit_expireDate->text().toStdString();

    if(ui->lineEdit_balance->text().toStdString()!=""){
    int balance = ui->lineEdit_balance->text().toDouble();
    if(cardNum != "" && csv != "" && expireDay != ""){
        if(balance > 1000){
            myOrderDam->completeOrder(this->myOrder);
            completeOrder();
        }else{
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("We excepet at least $1000 balanec as a economical insurance for adopting the pet."));
            QTimer::singleShot(5000,m_box,SLOT(accept()));
            m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
            m_box->exec();
        }
    }else{
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Warnign"),QString("Incomplete Infomation"));
        QTimer::singleShot(1000,m_box,SLOT(accept()));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
    }
    }
}
void payment::completeOrder()
{
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_6->setVisible(false);
    ui->lineEdit_balance->setVisible(false);
    ui->lineEdit_csv->setVisible(false);
    ui->lineEdit_cardNum->setVisible(false);
    ui->lineEdit_expireDate->setVisible(false);
    ui->pushButton_pay->setVisible(false);
    ui->pushButton_cancel->setVisible(false);
    ui->pushButton_delete->setVisible(false);
    ui->label_5->setVisible(true);
    ui->label_5->setText("Congraduation! You just finshed this adoption!");

}
