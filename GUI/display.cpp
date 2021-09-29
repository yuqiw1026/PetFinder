#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);


    this->setStyleSheet("background-color:rgb(255,255,255);}");
    this->setWindowTitle("Display");
}

display::~display()
{
    delete ui;
}


