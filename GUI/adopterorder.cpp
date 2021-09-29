#include "adopterorder.h"
#include "ui_adopterorder.h"
#include "QScrollBar"

adopterorder::adopterorder(QWidget *parent, OrderDam* orderDam) :
    QWidget(parent),
    ui(new Ui::adopterorder)
{
    ui->setupUi(this);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->toolButton_home->setStyleSheet("QToolButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                                       "background:#FFFFFF;"
                                                       "padding-top:20px;"
                                                       "padding-bottom:20px;"
                                                       "padding-left:3px;"
                                                       "padding-right:3px;"
                                                       "border-left:1px solid #d7d7d7;}"
                                                       "QScrollBar::handle:vertical{"
                                                       "background:#dbdbdb;"
                                                       "border-radius:6px;"   //边角圆润
                                                       "min-height:80px;}"
                                                       "QScrollBar::handle:vertical:hover{"
                                                       "background:#d0d0d0;}"
                                                       "QScrollBar::add-line:vertical{"
                                                       "background:url(:/imgs/down.jpg) center no-repeat;}"
                                                       "QScrollBar::sub-line:vertical{"
                                                       "background:url(:/imgs/up.jpg) center no-repeat;}");
    myOrderDam = orderDam;
    setWindowTitle("My Order");

}

adopterorder::~adopterorder()
{
    delete ui;
}
void adopterorder::adopterorderReceivesshow(){
    receiveRequestCreated();
    this->show();
}

void adopterorder::on_toolButton_home_clicked()
{
    this->hide();
    emit adopterorderShowmainwindow();
}

void adopterorder::receiveRequestCreated(){
    QList<QPushButton*> btns = ui->scrollAreaWidgetContents->findChildren<QPushButton*>();
    foreach(QPushButton* btn, btns)
    {
        delete btn;
    }
   // myOrderDam->read();
    if(this->myAdopter != nullptr){
        vector<Order*>* orders = myOrderDam->getOrdersForOneAdopter(this->myAdopter->getID());
        cout << "size: " << orders->size()<< endl;
        for(int i = 0; i < orders->size(); i++)
        {
            cout << "searching" << endl;
            if((*orders)[i]->getAdopterID() == this->myAdopter->getID()){
                QPushButton *pBtn = new QPushButton();
                pBtn->setText(QString("Order%1").arg(i));
                pBtn->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);font-family:'Adobe Gothic Std';font-size:18px;color:rgb(255,255,255);border-radius:6px;}");
                pBtn->setMinimumSize(QSize(60,50));   //width height
                string status = (*orders)[i]->getStatus();
                connect(pBtn, SIGNAL(clicked()),new payment(0,status,(*orders)[i]),SLOT(paymentreceiveshow()));
                pLayout->addWidget(pBtn);
            }
        }
    }
    ui->scrollAreaWidgetContents->setLayout(pLayout);
}
