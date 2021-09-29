#include "dog.h"
#include "ui_dog.h"
#include <QString>
#include "QScrollBar"

Dog::Dog(QWidget *parent, FileReader* fileReader, SearchEngine* searchEngine) :
    QDialog(parent),
    ui(new Ui::Dog)
{
    ui->setupUi(this);
    this->setFixedWidth(1200);

    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
   // this->setStyleSheet("background-color:rgb(255,255,255);}");
    this->setWindowTitle("Dogs");
    ui->pushButton_search->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    //ui->toolButton_home->setStyleSheet("QToolButton{border:0px;background-color:rgb(254,191,139);}");
     ui->toolButton_home->setStyleSheet("QToolButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                                       "background:#FFFFFF;"
                                                       "padding-top:20px;"
                                                       "padding-bottom:20px;"
                                                       "padding-left:3px;"
                                                       "padding-right:3px;"
                                                       "border-left:1px solid #d7d7d7;}"
                                                       "QScrollBar::handle:vertical{"
                                                       "background:#dbdbdb;"
                                                       "border-radius:6px;"   //边角圆润
                                                       "min-height:80px;}"
                                                       "QScrollBar::handle:vertical:hover{"
                                                       "background:#d0d0d0;}"
                                                       "QScrollBar::add-line:vertical{"
                                                       "background:url(:/imgs/down.jpg) center no-repeat;}"
                                                       "QScrollBar::sub-line:vertical{"
                                                       "background:url(:/imgs/up.jpg) center no-repeat;}");
    QStringList lst;
    string temp;
    this->fileReader = fileReader;
    auto itr = this->fileReader->states->begin();
    for(int i = 0; i < 52 ; i++){
        temp =  (*itr);
        lst << QString::fromStdString(temp);
        itr++;
    }
    ui->comboBoxStates->addItems(lst);
    auto completer = new QCompleter(lst, this);

    completer->setFilterMode(Qt::MatchContains);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    ui->comboBoxStates->setCompleter(completer);

    QLineEdit * LINE = new QLineEdit();
    //LINE->setStyleSheet("border:none;font-size:26px;font-weight:bold;color:#5f666e;background:transparent;");
    LINE->setPlaceholderText("Please choose a state first");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    this->searchEngine = searchEngine;

}

Dog::~Dog()
{
    delete ui;
}


void Dog::dogReceiveshow(){
    this->show();
}


void Dog::on_toolButton_home_clicked()
{
    this->hide();
    emit dogShowmainwindow();
}

void Dog::receivesTranslateToSpanish(){
    QLineEdit * LINE = new QLineEdit();
    //LINE->setStyleSheet("border:none;font-size:26px;font-weight:bold;color:#5f666e;background:transparent;");
    LINE->setPlaceholderText("Primero elija un estado");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    ui->comboBox_DogLanguage->setCurrentIndex(0);

    ui->label->setText("Por favor elija un estado");
    ui->label_2->setText("Por favor elija una ciudad");
    ui->lineEdit_SearchText->setText("Ingrese su nombre");
    ui->pushButton_search->setText("Buscar");
    ui->comboBox_DogLanguage->setItemText(0,"El lenguaje");
    ui->comboBox_DogLanguage->setItemText(1,"el inglés");
    ui->comboBox_DogLanguage->setItemText(2,"el español");
    ui->comboBox_SortBy->setItemText(0,"Ordenar por:");
    ui->comboBox_SortBy->setItemText(1,"Mejor partido");
    ui->comboBox_SortBy->setItemText(2,"Distancia (de menor a mayor)");
    ui->comboBox_SortBy->setItemText(3,"Distancia (de mayor a menor)");
    ui->combobox_Breeds->setItemText(0,"Razas");
    ui->combobox_Breeds->setItemText(1,"Rizo americano");
    ui->combobox_Age->setItemText(0,"Edad");
    ui->combobox_Age->setItemText(1,"gatito");
    ui->combobox_Age->setItemText(2,"adulto");
    ui->comboBox_Gender->setItemText(0,"Género");
    ui->comboBox_Gender->setItemText(1,"Mujer");
    ui->comboBox_Gender->setItemText(2,"Masculino");
    ui->comboBox_Size->setItemText(0,"Tamaño");
    ui->comboBox_Size->setItemText(1,"pequeña");
    ui->comboBox_Size->setItemText(2,"medio");
    ui->comboBox_Size->setItemText(3,"grande");
    ui->comboBox_Color->setItemText(0,"Color");
    ui->comboBox_Color->setItemText(1,"negro");
    ui->comboBox_Color->setItemText(2,"marrón");
    ui->comboBox_Color->setItemText(3,"gris");
    ui->comboBox_Color->setItemText(4,"blanco");
    ui->comboBox_Color->setItemText(5,"amarillo");
    ui->comboBox_Color->setItemText(6,"manchado");
    ui->comboBox_Color->setItemText(7,"banda");
    ui->comboBox_Color->setItemText(8,"mezclado");
    ui->comboBox_CoatLength->setItemText(0,"Longitud de la capa");
    ui->comboBox_CoatLength->setItemText(1,"sin cabello");
    ui->comboBox_CoatLength->setItemText(2,"cabello corto");
    ui->comboBox_CoatLength->setItemText(3,"haircabello de longitud media");
    ui->comboBox_CoatLength->setItemText(4,"pelo largo");
    ui->comboBox_activeLevel->setItemText(0,"Nivel activo");
    ui->comboBox_CoatLength->setItemText(1,"Bajo");
    ui->comboBox_CoatLength->setItemText(2,"medio");
    ui->comboBox_CoatLength->setItemText(3,"elevado");
}

void Dog::receivesTranslateToEnglish(){

    QLineEdit * LINE = new QLineEdit();
    //LINE->setStyleSheet("border:none;font-size:26px;font-weight:bold;color:#5f666e;background:transparent;");
    LINE->setPlaceholderText("Please choose a state first");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    ui->comboBox_DogLanguage->setCurrentIndex(0);

    ui->label->setText("Please choose a state");
    ui->label_2->setText("Please choose a city");
    ui->lineEdit_SearchText->setText("Enter Name");
    ui->pushButton_search->setText("Search");
    ui->comboBox_DogLanguage->setItemText(0,"Language");
    ui->comboBox_DogLanguage->setItemText(1,"English");
    ui->comboBox_DogLanguage->setItemText(2,"Spanish");
    ui->comboBox_SortBy->setItemText(0,"Sort by:");
    ui->comboBox_SortBy->setItemText(1,"Best Match");
    ui->comboBox_SortBy->setItemText(2,"Distance(from lowest to highest)");
    ui->comboBox_SortBy->setItemText(3,"Distance(from highest to lowest)");
    ui->combobox_Breeds->setItemText(0,"Breeds");
    ui->combobox_Breeds->setItemText(1,"American Curl");
    ui->combobox_Age->setItemText(0,"Age");
    ui->combobox_Age->setItemText(1,"kitten");
    ui->combobox_Age->setItemText(2,"adult");
    ui->comboBox_Gender->setItemText(0,"Gender");
    ui->comboBox_Gender->setItemText(1,"Female");
    ui->comboBox_Gender->setItemText(2,"Male");
    ui->comboBox_Size->setItemText(0,"Size");
    ui->comboBox_Size->setItemText(1,"small");
    ui->comboBox_Size->setItemText(2,"mid");
    ui->comboBox_Size->setItemText(3,"large");
    ui->comboBox_Color->setItemText(0,"Color");
    ui->comboBox_Color->setItemText(1,"black");
    ui->comboBox_Color->setItemText(2,"brown");
    ui->comboBox_Color->setItemText(3,"grey");
    ui->comboBox_Color->setItemText(4,"white");
    ui->comboBox_Color->setItemText(5,"yellow");
    ui->comboBox_Color->setItemText(6,"spotted");
    ui->comboBox_Color->setItemText(7,"strip");
    ui->comboBox_Color->setItemText(8,"mixed");
    ui->comboBox_CoatLength->setItemText(0,"Coat length");
    ui->comboBox_CoatLength->setItemText(1,"no hair");
    ui->comboBox_CoatLength->setItemText(2,"short hair");
    ui->comboBox_CoatLength->setItemText(3,"mid-length hair");
    ui->comboBox_CoatLength->setItemText(4,"long hair");
    ui->comboBox_activeLevel->setItemText(0,"Active level");
    ui->comboBox_CoatLength->setItemText(1,"Low");
    ui->comboBox_CoatLength->setItemText(2,"mid");
    ui->comboBox_CoatLength->setItemText(3,"high");
}

void Dog::on_comboBox_DogLanguage_currentIndexChanged(int index)
{
    if(index == 1){
        receivesTranslateToEnglish();
        emit translateToEnglish();
    }else if(index == 2){
        receivesTranslateToSpanish();
        emit translateToSpanish();
    }
}

void Dog::on_comboBoxStates_activated(const QString &arg1)
{

    if(ui->comboBoxStates->currentText().toStdString() == "" ){
        ui->comboBoxCities->lineEdit()->clear();
        ui->comboBoxCities->lineEdit()->setReadOnly(true);
        ui->comboBoxCities->clear();
        return;
    }
    ui->comboBoxCities->lineEdit()->clear();
    ui->comboBoxCities->lineEdit()->setReadOnly(false);

ui->comboBoxCities->setMaxVisibleItems(10);

 QStringList lst;
 string temp;
 const QString state = arg1;
 vector<string>* resultCities = this->fileReader->getCitiesByState(state.toStdString());
 for(int i = 1; i < resultCities->size() ; i++){
     temp =  (*resultCities)[i];
     lst << QString::fromStdString(temp);

 }
 cout << resultCities->size() << endl;
 ui->comboBoxCities->addItems(lst);
 auto completer = new QCompleter(lst, this);

 completer->setFilterMode(Qt::MatchContains);
 completer->setCaseSensitivity(Qt::CaseInsensitive);

 ui->comboBoxCities->setCompleter(completer);
}
