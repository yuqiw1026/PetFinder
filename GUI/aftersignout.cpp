#include "aftersignout.h"
#include "ui_aftersignout.h"

Aftersignout::Aftersignout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Aftersignout)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);
    this->setWindowTitle("Sign out");

    QPalette pe;

    pe.setColor(QPalette::WindowText, QColor(104,86,76));
    ui->label_signOut->setPalette(pe);

}

Aftersignout::~Aftersignout()
{
    delete ui;
}
