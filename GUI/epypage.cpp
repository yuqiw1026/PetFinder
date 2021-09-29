#include "epypage.h"
#include "ui_epypage.h"

epypage::epypage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::epypage)
{
    ui->setupUi(this);
}

epypage::~epypage()
{
    delete ui;
}
