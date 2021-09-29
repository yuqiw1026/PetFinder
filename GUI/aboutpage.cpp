#include "aboutpage.h"
#include "ui_aboutpage.h"

aboutpage::aboutpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutpage)
{
    ui->setupUi(this);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    QPalette pe;
    ui->infosection->setFixedWidth(720);

    ui->infosection->setStyleSheet("background-color: rgba( 255, 255, 255, 0% );" );
    ui->pushButtonPetFinder_4->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");

    pe.setColor(QPalette::WindowText, QColor(0,0,0));
    //改颜色；标注
}

aboutpage::~aboutpage()
{
    delete ui;
}

void aboutpage::on_pushButtonPetFinder_4_clicked()
{
    this->hide();

    emit aboutShowmainwindow();
}
void aboutpage::aboutReceiveshow(){
    this->show();
}
