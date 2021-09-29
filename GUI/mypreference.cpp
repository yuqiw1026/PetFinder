#include "mypreference.h"
#include "ui_mypreference.h"

mypreference::mypreference(QWidget *parent, SearchEngine* searchEngine) :
    QWidget(parent),
    ui(new Ui::mypreference)
{
    ui->setupUi(this);
    setWindowTitle("preference");
    this->setFixedSize(800,720);

    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->mySearchEngine = searchEngine;

    QPalette pe;

    pe.setColor(QPalette::WindowText, QColor(0,0,0));
    //改颜色；标注


    ui->label_bottomspace->setPalette(pe);
    ui->pushButton_Search->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,139);border-radius:6px;}");
    ui->toolButton_home->setStyleSheet("QToolButton{border:0px;background-color:rgb(254,191,139);border-radius:6px;}");

}

mypreference::~mypreference()
{
    delete ui;
}


void mypreference::on_toolButton_home_clicked()
{
    this->hide();
    emit prefShowmainwindow();

}

void mypreference::prefReceivesshow(){
    this->show();
}

void mypreference::receivesTranslateToSpanish(){
    ui->comboBox_Language->setCurrentIndex(0);
    ui->comboBox_Language->setItemText(0,"El lenguaje");
    ui->comboBox_Language->setItemText(1,"el inglés");
    ui->comboBox_Language->setItemText(2,"el español");
    ui->label_bottomspace->setText("¡Gracias! \nCompletemos un formulario rápido\npara ayudarnos a encontrar las mascotas de sus sueños.");
    ui->label_6->setText("Me gustaría adoptar un ");
    ui->label->setText("Me gustaría adoptar un ");
    ui->label_2->setText("Me gustaría adoptar un");
    ui->label_7->setText("Me gustaría adoptar una mascota de tamaño");
    ui->label_9->setText("El color de la mascota de mis sueños debería ser");
    ui->label_8->setText("El nivel de actividad de la mascota de mis sueños debería ser");
//    ui->comboBox_Species->setItemText(0,"Seleccionar especies");
//    ui->comboBox_Species->setItemText(1,"Gato");
//    ui->comboBox_Species->setItemText(2,"Perro");
//    ui->comboBox_Species->setItemText(3,"Otros");
//    ui->comboBox_Age->setItemText(0,"Seleccionar edad");
//    ui->comboBox_Age->setItemText(1,"bebé");
//    ui->comboBox_Age->setItemText(2,"Adulto");
//    ui->comboBox_Age->setItemText(3,"Viejo");
//    ui->comboBox_Age->setItemText(4,"Sin preferencia de edad");
//    ui->comboBox_Gender->setItemText(0,"seleccione género");
//    ui->comboBox_Gender->setItemText(1,"Mujer");
//    ui->comboBox_Gender->setItemText(2,"Masculino");
//    ui->comboBox_Gender->setItemText(3,"Sin preferencia de género");
//    ui->comboBox_Size->setItemText(0,"selecciona el tamaño");
//    ui->comboBox_Size->setItemText(1,"pequeña");
//    ui->comboBox_Size->setItemText(2,"medio");
//    ui->comboBox_Size->setItemText(3,"grande");
//    ui->comboBox_Size->setItemText(4,"sin preferencia de tamaño");
//    ui->comboBox_ColorPattern->setItemText(0,"Seleccionar color / patrón");
//    ui->comboBox_ColorPattern->setItemText(1,"blanco");
//    ui->comboBox_ColorPattern->setItemText(2,"negro");
//    ui->comboBox_ColorPattern->setItemText(3,"gris");
//    ui->comboBox_ColorPattern->setItemText(4,"marrón");
//    ui->comboBox_ColorPattern->setItemText(5,"mezclado");
//    ui->comboBox_ColorPattern->setItemText(6,"manchado");
//    ui->comboBox_ColorPattern->setItemText(7,"despojado");
//    ui->comboBox_ColorPattern->setItemText(8,"sin preferencias");
//    ui->comboBox_Activity->setItemText(0," ");
//    ui->comboBox_Activity->setItemText(1,"bajo");
//    ui->comboBox_Activity->setItemText(2,"medio");
//    ui->comboBox_Activity->setItemText(3,"elevado");
//    ui->comboBox_Activity->setItemText(4,"sin preferencias");
    ui->pushButton_Search->setText("Guardar mis preferencias");
}

void mypreference::receivesTranslateToEnglish(){
    ui->comboBox_Language->setCurrentIndex(0);
    ui->comboBox_Language->setItemText(0,"Language");
    ui->comboBox_Language->setItemText(1,"English");
    ui->comboBox_Language->setItemText(2,"Spanish");
    ui->label_bottomspace->setText("Thanks!\nLet's fill out a quick form\nto help us find your dream pets!");
    ui->label_6->setText("I'd like to adopt a ");
    ui->label->setText("I'd like to adopt a ");
    ui->label_2->setText("I'd like to adopt a ");
    ui->label_7->setText("I'd like to adopt a pet of size");
    ui->label_9->setText("My dream pet's color should be");
    ui->label_8->setText("My dream pet's activity level should be");
//    ui->comboBox_Species->setItemText(0,"Select species");
//    ui->comboBox_Species->setItemText(1,"Cat");
//    ui->comboBox_Species->setItemText(2,"Dog");
//    ui->comboBox_Species->setItemText(3,"Others");
//    ui->comboBox_Age->setItemText(0,"Select age");
//    ui->comboBox_Age->setItemText(1,"baby");
//    ui->comboBox_Age->setItemText(2,"Adult");
//    ui->comboBox_Age->setItemText(3,"Old");
//    ui->comboBox_Age->setItemText(4,"No age preference");
//    ui->comboBox_Gender->setItemText(0,"select gender");
//    ui->comboBox_Gender->setItemText(1,"Female");
//    ui->comboBox_Gender->setItemText(2,"Male");
//    ui->comboBox_Gender->setItemText(3,"No gender preference");
//    ui->comboBox_Size->setItemText(0,"select size");
//    ui->comboBox_Size->setItemText(1,"small");
//    ui->comboBox_Size->setItemText(2,"medium");
//    ui->comboBox_Size->setItemText(3,"large");
//    ui->comboBox_Size->setItemText(4,"no size preference");
//    ui->comboBox_ColorPattern->setItemText(0,"Select color/pattern");
//    ui->comboBox_ColorPattern->setItemText(1,"white");
//    ui->comboBox_ColorPattern->setItemText(2,"black");
//    ui->comboBox_ColorPattern->setItemText(3,"grey");
//    ui->comboBox_ColorPattern->setItemText(4,"brown");
//    ui->comboBox_ColorPattern->setItemText(5,"mixed");
//    ui->comboBox_ColorPattern->setItemText(6,"spotted");
//    ui->comboBox_ColorPattern->setItemText(7,"stripped");
//    ui->comboBox_ColorPattern->setItemText(8,"no preference");
//    ui->comboBox_Activity->setItemText(0," ");
//    ui->comboBox_Activity->setItemText(1,"low");
//    ui->comboBox_Activity->setItemText(2,"medium");
//    ui->comboBox_Activity->setItemText(3,"high");
//    ui->comboBox_Activity->setItemText(4,"no preference");
    ui->pushButton_Search->setText("Save my preferences");
}


void mypreference::on_comboBox_Language_currentIndexChanged(int index)
{
    if(index == 1){
        receivesTranslateToEnglish();
        emit translateToEnglish();
    }else if(index == 2){
        receivesTranslateToSpanish();
        emit translateToSpanish();
    }

}

void mypreference::on_pushButton_Search_clicked()
{

    string energyLevel;
    string color;
    string coatLength;
    string size;

    string temp_energyLevel = ui->comboBox_1->currentText().toStdString();
    string temp_color = ui->comboBox_2->currentText().toStdString();
    string temp_coatLength = ui->comboBox_3->currentText().toStdString();
    string temp_size = ui->comboBox_4->currentText().toStdString();
    if(temp_energyLevel == "I want some accompany"){
        energyLevel = "low";
    }else if(temp_energyLevel == "I want to play with animals"){
        energyLevel = "high";
    }else if(temp_energyLevel == "I am not sure"){
        energyLevel = "mid";
    }
    color = temp_color;
    if(temp_coatLength == "Yes!"){
        coatLength = "short";
    }else if(temp_coatLength == "To some degree."){
        coatLength = "mid-length";
    }else if(temp_coatLength == "No, not at all."){
        coatLength = "long";
    }
    if(temp_size == "mini & cute!"){
        size = "small";
    }else if(temp_size == "big & strong"){
        size = "medium";
    }else if(temp_size == "no preference"){
        size = "large";
    }

    if(energyLevel != "" && color != "" && coatLength != "" && size != ""){
        //string preference = energyLevel + ", " + color + ", " + coatLength + ", " + size;
        this->mySearchEngine->addNewWishList(this->myAdopter,energyLevel,coatLength,color,size);
    }else{
        QMessageBox *m_box;
        m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Incomplete Information!"));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
    }
}
