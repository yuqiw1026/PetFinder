#include "animalinfor.h"
#include "ui_animalinfor.h"

animalinfor::animalinfor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::animalinfor)
{
    ui->setupUi(this);
}

animalinfor::~animalinfor()
{
    delete ui;
}
