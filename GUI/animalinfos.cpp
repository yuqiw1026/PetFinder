#include "animalinfos.h"
#include "ui_animalinfos.h"

AnimalInfos::AnimalInfos(QWidget *parent, AnimalDam* animalDam) :
    QWidget(parent),
    ui(new Ui::AnimalInfos)
{
    ui->setupUi(this);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    myAnimalDam = animalDam;
    current = 0;
    qryAnimals  = animalDam->getAllAnimalsInfo();
    updateTable(current);

}

AnimalInfos::~AnimalInfos()
{
    delete ui;
}


void AnimalInfos::anminfoReceiveshow(){
    this->show();
}

void AnimalInfos::on_toolButton_clicked()
{
    this->hide();
    emit anminfoShowmainwindow();
}

//Employee add new other species animal
void AnimalInfos::on_pushButton_addAnimal_clicked()
{
    int shelterID = -1;
    string name = ui->name->text().toStdString();
    shelterID = ui->shelterID->text().toInt();
    string species=ui->species->text().toStdString();
    string breed = ui->lineEdit_breeds->text().toStdString();
    string gender = ui->comboBox_Gender_6->currentText().toStdString();
    string age=ui->combobox_Age_6->currentText().toStdString();
    string size=ui->comboBox_Size_6->currentText().toStdString();
    string color=ui->comboBox_Color_6->currentText().toStdString();
    string coatLength=ui->comboBox_CoatLength_6->currentText().toStdString();
    string energylvl = ui->comboBox_activeLevel_6->currentText().toStdString();
    string picLocation = ui->otherpicaddress->text().toStdString();

    if(name != "" && shelterID != -1 && species != "" && breed != "" && gender != "" &&
            age != "" && size != "" && color != "" && coatLength != "" && energylvl != ""
            && picLocation != ""){


        if(myAnimalDam->addNewAnimal(shelterID, species, breed, name, gender,age, size, color, coatLength, energylvl, picLocation)){
            ui->label_status->setText(QString::fromStdString("The " + species + " " + name +" is added successfully" ));
        }else{
            ui->label_status->setText(QString::fromStdString("The " + species + " " + name +" fail to add" ));
        }

    }else{
        ui->label_status->setText(QString::fromStdString("Missing information"));
    }

}

void AnimalInfos::on_deleteanimal_clicked()
{
    int animalid = ui->delete_input_id->text().toInt();
    if(myAnimalDam->hasAnimal(animalid)){
        myAnimalDam->remove(animalid);
    }else{
        QMessageBox *m_box=new QMessageBox(QMessageBox::Information,QString("Error"),QString("Animal ID does not exist"));
        m_box->exec();
    }
    updateTable(current);
}



//void AnimalInfos::on_searchbyid_clicked()
//{
//    int animalid = ui->edit_input_id->text().toInt();
//    if(myAnimalDam->hasAnimal(animalid)){

//    }else{
//        QMessageBox *m_box=new QMessageBox(QMessageBox::Information,QString("Error"),QString("Animal ID does not exist"));
//        m_box->exec();
//    }
//}

void AnimalInfos::updateTable(int currentIndex)
{
  ui->animalTable->setRowCount(0);

    qryAnimals  = myAnimalDam->getAllAnimalsInfo();
    for(int i = 0; i < currentIndex; i++){
        if(qryAnimals->next()){

        }
    }
    for(int i =0; i < 20; i++)
    {
        if(qryAnimals->next()){
            QString id = qryAnimals->value(0).toString();
            QString shelterID = qryAnimals->value(1).toString();
            QString species = qryAnimals->value(2).toString();
            QString breed = qryAnimals->value(3).toString();
            QString name = qryAnimals->value(4).toString();
            QString gender = qryAnimals->value(5).toString();
            QString age = qryAnimals->value(6).toString();
            QString size = qryAnimals->value(7).toString();
            ui->animalTable->insertRow(i);
            ui->animalTable->setItem(i,0, new QTableWidgetItem(id));
            ui->animalTable->setItem(i,1, new QTableWidgetItem(shelterID));
            ui->animalTable->setItem(i,3, new QTableWidgetItem(species));
            ui->animalTable->setItem(i,4, new QTableWidgetItem(breed));
            ui->animalTable->setItem(i,2, new QTableWidgetItem(name));
            ui->animalTable->setItem(i,5, new QTableWidgetItem(gender));
            ui->animalTable->setItem(i,6, new QTableWidgetItem(age));
            ui->animalTable->setItem(i,7, new QTableWidgetItem(size));
        }
    }
}

void AnimalInfos::on_pushButton_pre_clicked()
{
    if(current - 20 > 0){
        current -= 20;

    }else{
        current = 0;
    }
    updateTable(current);
}

void AnimalInfos::on_pushButton_next_clicked()
{

    current += 20;
    updateTable(current);
}
