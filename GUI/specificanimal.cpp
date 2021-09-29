#include "specificanimal.h"
#include "ui_specificanimal.h"

specificanimal::specificanimal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::specificanimal)
{
    ui->setupUi(this);
}

specificanimal::~specificanimal()
{
    delete ui;
}
