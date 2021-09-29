#include "animalinfo.h"
#include "ui_animalinfo.h"

AnimalInfo::AnimalInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalInfo)
{
    ui->setupUi(this);
}

AnimalInfo::~AnimalInfo()
{
    delete ui;
}
