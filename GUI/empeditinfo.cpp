#include "empeditinfo.h"
#include "ui_empeditinfo.h"

empeditinfo::empeditinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::empeditinfo)
{
    ui->setupUi(this);
}

empeditinfo::~empeditinfo()
{
    delete ui;
}
