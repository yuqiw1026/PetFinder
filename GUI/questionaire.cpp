#include "questionaire.h"
#include "ui_questionaire.h"

questionaire::questionaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questionaire)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:rgb(255,255,255);}");
    this->setWindowTitle("Questionaire");
    ui->pushButton_Search->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
}

questionaire::~questionaire()
{
    delete ui;
}

void questionaire::on_pushButton_2_clicked()
{
    this->hide();
    dpage=new display;
    dpage->show();
}
