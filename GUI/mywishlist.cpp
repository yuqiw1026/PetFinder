#include "mywishlist.h"
#include "ui_mywishlist.h"

mywishlist::mywishlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywishlist)
{
    ui->setupUi(this);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    QPalette pe;

    pe.setColor(QPalette::WindowText, QColor(0,0,0));
    //改颜色；标注
}

mywishlist::~mywishlist()
{
    delete ui;
}


void mywishlist::wishlistReceivesshow(){
    this->show();
}
void mywishlist::on_toolButton_home_clicked()
{
    this->hide();
    emit wlShowmainwindow();
}
