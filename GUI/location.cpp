#include "location.h"
#include "ui_location.h"

Location::Location(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Location)
{
    ui->setupUi(this);
}

Location::~Location()
{
    delete ui;
}

void Location::on_pushButton_clicked()
{

}
