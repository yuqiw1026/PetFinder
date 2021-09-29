#include "resultanimal.h"
#include "ui_resultanimal.h"

//resultanimal::resultanimal(QWidget *parent) :
ResultAnimal::ResultAnimal(QWidget *parent, OrderDam* orderDam) :
    QWidget(parent),
    ui(new Ui::resultanimal)
{
    ui->setupUi(this);
    this->myOrderDam = orderDam;

    QPixmap bkgnd(":imgs/Preference2.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

}

ResultAnimal::~ResultAnimal()
{
    delete ui;
}

void ResultAnimal::on_pushButton_clicked()
{
    if(this->myAnimal == nullptr){
        cout << "null animal" << endl;

    }
    if(this->adopter == nullptr){
        cout << "null adopter" << endl;

    }
    int adopterID = this->adopter->getID();
    int animalID = this->myAnimal->getID();
    cout << adopterID << endl;
    cout << animalID << endl;
    if(this->myOrderDam == nullptr){
        cout << "null order dam" << endl;
    }
    string status = "Waiting For Approval";
    int likeNum = 0;
    if(myOrderDam->addNewOrder(adopterID,animalID,status,likeNum)){
        ui->label_info->setText("Success!");
        QMessageBox *mbox = new QMessageBox();
        mbox->setWindowTitle(tr("Request sent successfully"));
        mbox->setText("Adoption request sent sscuessfully! Please wait for us to process.");
        mbox->setStyleSheet("background-color: rgb(255, 255, 255);");
        mbox->exec();
    } else{
        ui->label_info->setText("Failed!");
    }

}

void ResultAnimal::reltanmReceiveshow(){
 this->show();
}

void ResultAnimal::updateDisplay(double dist)
{
    if(myAnimal != nullptr){
    ui->label_shelterID->setText(QString::fromStdString(to_string(this->myAnimal->getShelterID())));
    ui->label_species->setText(QString::fromStdString(this->myAnimal->species));
    ui->label_breed->setText(QString::fromStdString(this->myAnimal->breed));
    ui->label_name->setText(QString::fromStdString(this->myAnimal->getName()));
    ui->label_age->setText(QString::fromStdString(this->myAnimal->age));
    ui->label_gender->setText(QString::fromStdString(this->myAnimal->getGender()));
    ui->label_size->setText(QString::fromStdString(this->myAnimal->size));
    ui->label_color->setText(QString::fromStdString(this->myAnimal->color));
    ui->label_distance->setText(QString::fromStdString(to_string(dist)));
    ui->label_coatLength->setText(QString::fromStdString(this->myAnimal->coatLength));
    ui->label_energyLevel->setText(QString::fromStdString(this->myAnimal->energyLevel));
    ui->label_address->setText(QString::fromStdString(address));
    }
}
