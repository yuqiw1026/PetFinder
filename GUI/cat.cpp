#include "cat.h"
#include "ui_cat.h"
#include <QString>
#include "QScrollBar"

Cat::Cat(QWidget *parent, FileReader* fileReader, SearchEngine* searchEngine, ResultAnimal* resultAniamlPage) :
    QDialog(parent),
    ui(new Ui::Cat)
{
    ui->setupUi(this);
    this->setFixedWidth(1200);

    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setWindowTitle("Cats");
    ui->pushButton_search->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->toolButton_home->setStyleSheet("QToolButton{border:0px;background-color:rgb(254,191,139);border-radius:6px;}");
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
                                                       "border-radius:6px;"
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
    LINE->setPlaceholderText("Please choose a state first");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    this->searchEngine = searchEngine;

    display = new vector<QLabel*>();
    display->push_back(ui->cat1);
    display->push_back(ui->cat2);
    display->push_back(ui->cat3);
    display->push_back(ui->cat4);
    display->push_back(ui->cat5);
    display->push_back(ui->cat6);
    display->push_back(ui->cat7);
    display->push_back(ui->cat8);
    display->push_back(ui->cat9);

    for(int i = 0; i < display->size(); i++){
         (*display)[i]->installEventFilter(this);
    }
    currentIndex = 0;
    briefMessage = new QLabel();
    briefMessage->setStyleSheet("QLabel { background-color : white; }");
    briefMessage->hide();
    this->resultAnimalPage = resultAniamlPage;
    myAdopter = nullptr;
}

Cat::~Cat()
{
    delete ui;
}


void Cat::catReceiveshow(){
    this->show();
}

void Cat::on_toolButton_home_clicked()
{
    this->hide();
    /* mainpage=new MainWindow();
     mainpage->show();*/
     emit catShowmainwindow();
}

void Cat::on_comboBoxStates_activated(const QString &arg1)
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
 //cout << resultCities->size() << endl;
 ui->comboBoxCities->addItems(lst);
 auto completer = new QCompleter(lst, this);

 completer->setFilterMode(Qt::MatchContains);
 completer->setCaseSensitivity(Qt::CaseInsensitive);

 ui->comboBoxCities->setCompleter(completer);
}

void Cat::receivesTranslateToSpanish(){

    QLineEdit * LINE = new QLineEdit();
    //LINE->setStyleSheet("border:none;font-size:26px;font-weight:bold;color:#5f666e;background:transparent;");
    LINE->setPlaceholderText("Primero elija un estado");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    ui->comboBox_CatLanguage->setCurrentIndex(0);

    ui->label->setText("Por favor elija un estado");
    ui->label_2->setText("Por favor elija una ciudad");
    ui->lineEdit_name->setText("Ingrese su nombre");
    ui->pushButton_search->setText("Buscar");
    ui->comboBox_CatLanguage->setItemText(0,"El lenguaje");
    ui->comboBox_CatLanguage->setItemText(1,"el inglés");
    ui->comboBox_CatLanguage->setItemText(2,"el español");
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

void Cat::receivesTranslateToEnglish(){


    QLineEdit * LINE = new QLineEdit();
    //LINE->setStyleSheet("border:none;font-size:26px;font-weight:bold;color:#5f666e;background:transparent;");
    LINE->setPlaceholderText("Please choose a state first");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);
    ui->comboBox_CatLanguage->setCurrentIndex(0);

    ui->label->setText("Please choose a state");
    ui->label_2->setText("Please choose a city");
    ui->lineEdit_name->setText("Enter Name");
    ui->pushButton_search->setText("Search");
    ui->comboBox_CatLanguage->setItemText(0,"Language");
    ui->comboBox_CatLanguage->setItemText(1,"English");
    ui->comboBox_CatLanguage->setItemText(2,"Spanish");
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

void Cat::on_comboBox_CatLanguage_currentIndexChanged(int index)
{
    if(index == 1){
        receivesTranslateToEnglish();
        emit translateToEnglish();
    }else if(index == 2){
        receivesTranslateToSpanish();
        emit translateToSpanish();
    }

}

void addToMapHelper(map<int, int >* map, vector<Animal*>* list)
{
    for(int i = 0; i < list->size();i++){
        if( map->insert(make_pair((*list)[i]->getID(), 1)).second == false){
            for(auto itr = map->begin(); itr != map->end(); itr++){
                if(itr->first == (*list)[i]->getID()){
                    itr->second++;
                }
            }
        }
    }
}

void Cat::on_pushButton_search_clicked()
{
    for(int i = 0; i < display->size(); i++){
        (*display)[i]->clear();
    }
    currentIndex = 0;
    int change = 0;
    map<int, int >* temp = new map<int,int>();
    vector<Animal*>* breedss;
    vector<Animal*>* genderss;
    vector<Animal*>* agess;
    vector<Animal*>* namess;
    vector<Animal*>* sizess;
    vector<Animal*>* colorss;
    vector<Animal*>* coatLengthss;
    vector<Animal*>* energyLvlss;
    vector<int>* results = new vector<int>();
    vector<Animal*>* resultAnimals = new vector<Animal*>();
    string name = ui->lineEdit_name->text().toStdString();
    string species = "Cat";
    string breed = ui->combobox_Breeds->currentText().toStdString();
    string gender = ui->comboBox_Gender->currentText().toStdString();
    string age = ui->combobox_Age->currentText().toStdString();
    string size = ui->comboBox_Size->currentText().toStdString();
    string color = ui->comboBox_Color->currentText().toStdString();
    string coatLength = ui->comboBox_CoatLength->currentText().toStdString();
    string energylvl = ui->comboBox_activeLevel->currentText().toStdString();

    if(name != ""){
        namess = searchEngine->searchForOneInOneSpecies("Cat","Name", name);
        addToMapHelper(temp,namess);
        change++;
    }
    if( breed != ""){
        breedss =  searchEngine->searchForOneInOneSpecies("Cat","Breed", breed);
        addToMapHelper(temp,breedss);
        change++;
    }
    if(gender != "" ){
        genderss =  searchEngine->searchForOneInOneSpecies("Cat","Gender", gender);
        addToMapHelper(temp,genderss);
        change++;
    }
    if(age != ""){
        agess = searchEngine->searchForOneInOneSpecies("Cat","Age", age);
        addToMapHelper(temp,agess);
        change++;
    }
    if( size != ""){
        sizess = searchEngine->searchForOneInOneSpecies("Cat","Size", size);
        addToMapHelper(temp,sizess);
        change++;
    }
    if( color != ""){
        colorss = searchEngine->searchForOneInOneSpecies("Cat","Color", color);
        addToMapHelper(temp,colorss);
        change++;
    }
    if(coatLength != ""){
        coatLengthss = searchEngine->searchForOneInOneSpecies("Cat","CoatLength", coatLength);
        addToMapHelper(temp,coatLengthss);
        change++;
    }
    if(energylvl != ""){
        energyLvlss = searchEngine->searchForOneInOneSpecies("Cat","EnergyLevel", energylvl);
        addToMapHelper(temp,energyLvlss);
        change++;
    }

    for(auto itr = temp->begin(); itr != temp->end(); itr++){
        if(itr->second == change){
            results->push_back(itr->first);
        }
    }
    if(results->size()>0){
        resultAnimals = searchEngine->getAnimalsByIDs(results);
        finalResults = resultAnimals;
    }else{
        resultAnimals = new vector<Animal*>();
        finalResults = new vector<Animal*>();
    }

    map<double, Animal*>* sortedIncreasing = nullptr;
    if(ui->comboBox_SortBy->currentText().toStdString() == "Distance (from lowest to highest)"){
        if(this->myAdopter != nullptr && resultAnimals->size() > 0){
            sortedIncreasing = this->searchEngine->sortAnimalsOrderByDistance(resultAnimals, this->myAdopter);
            cout << sortedIncreasing->size() << endl;
            auto itr = sortedIncreasing->begin();
            cout << itr->second->getShelterID() << endl;
            itr++;
            cout << itr->second->getShelterID() << endl;
            itr++;
            cout << itr->second->getShelterID() << endl;
        }
    }else if(ui->comboBox_SortBy->currentText().toStdString() == "Best Match"){
        if(this->myAdopter != nullptr){
            if(this->searchEngine->adopterhasWishList(this->myAdopter)){
                resultAnimals =  BestMatch(resultAnimals);
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Fill Preferences Questionaire First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
                return;
            }
        }else{
            QMessageBox *m_box;
            m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
            m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
            m_box->exec();
            return;
        }

    }
    if(sortedIncreasing != nullptr && sortedIncreasing->size() > 0){
        //cout << "resultAnimalSize :" << resultAnimals->size() <<endl;
        resultAnimals->clear();
        finalResults->clear();
        //finalDistances = new vector<double>();
        for(auto itr =  sortedIncreasing->begin(); itr != sortedIncreasing->end(); itr++){
           resultAnimals->push_back(itr->second);
           //cout << itr->first << endl;
           //finalDistances->push_back(itr->first);
        }

        finalResults = resultAnimals;
        //cout << "working" <<endl;
    }
        cout << resultAnimals->size() << "again" << endl;
    int current = 0;
    while(resultAnimals->size() > 0 && current < 9 && currentIndex < resultAnimals->size()){

    QPixmap outPixmap = QPixmap((*resultAnimals)[currentIndex]->getPicLocation());
    (*display)[current]->setPixmap( outPixmap );
    (*display)[current]->setScaledContents( true );
    (*display)[current]->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    (*display)[current]->show();
    current++;
    currentIndex++;
    }
}


void Cat::on_pushButton_next_clicked()
{
    int current = 0;
    if((finalResults->size() > 0 && currentIndex < finalResults->size())){
    for(int i = 0; i < display->size(); i++){
        (*display)[i]->clear();
    }
    }
    while(finalResults->size() > 0 && current < 9 && currentIndex < finalResults->size()){

    QPixmap outPixmap = QPixmap((*finalResults)[currentIndex]->getPicLocation());

    (*display)[current]->setPixmap( outPixmap );
    (*display)[current]->setScaledContents( true );
    (*display)[current]->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    (*display)[current]->show();
    current++;
    currentIndex++;
    }
    //cout << "Current:" << currentIndex <<endl;
}


void Cat::on_pushButton_pre_clicked()
{
        currentIndex -=18;
        if(currentIndex < 0){
            currentIndex = 0;
        }
        int current = 0;
        for(int i = 0; i < display->size(); i++){
            (*display)[i]->clear();
        }
        while(finalResults->size() > 0 && current < 9 && currentIndex < finalResults->size()){
        QPixmap outPixmap = QPixmap((*finalResults)[currentIndex]->getPicLocation());
        (*display)[current]->setPixmap( outPixmap );
        (*display)[current]->setScaledContents( true );
        (*display)[current]->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        (*display)[current]->show();
        current++;
        currentIndex++;
        }

    //cout << "Current:" << currentIndex <<endl;
}

void labelSetText(Animal* animal, QLabel* label){
    string name = "Name: " + animal->getName() + "\n";
    string breed = "Breed: " + animal->breed + "\n";
    string age = "Age: "+animal->age+  "\n";
    string size = "Size: " + animal->size + "\n";
    string total = name + breed + age + size;
    label->setText(QString::fromStdString(total));
}

bool Cat::eventFilter(QObject *watched, QEvent *event)
{
    //光标位置
    QCursor *cursor;
    int x=cursor->pos().x();
    int y=cursor->pos().y();

    if(  (*display)[0] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible() && (*display)[0]->pixmap()){
            briefMessage->clear();
            if(finalResults != nullptr && finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-9],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[0],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }

        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[0]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-9];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[0];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }

    if(  (*display)[1] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible() && (*display)[1]->pixmap()){
            briefMessage->clear();
            if(finalResults != nullptr && finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-8],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[1],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }
        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();
        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[1]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-8];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[1];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[2] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible()&& (*display)[2]->pixmap()){
            briefMessage->clear();
            if(finalResults != nullptr && finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-7],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[2],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }
        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[2]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-7];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[2];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[3] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible() && (*display)[3]->pixmap()){
            briefMessage->clear();
            if(finalResults != nullptr &&  finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-6],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[3],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }
        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();
        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[3]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-6];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[3];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[4] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible()&& (*display)[4]->pixmap() ){
            briefMessage->clear();
            if(finalResults != nullptr &&  finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-5],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[4],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }

        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[4]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-5];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[4];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[5] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible()&& (*display)[5]->pixmap()){
            briefMessage->clear();
            if(finalResults != nullptr && finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-4],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[5],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }
        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[5]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-4];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[5];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[6] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible() && (*display)[6]->pixmap()){
            briefMessage->clear();
            if(finalResults != nullptr && finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-3],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[6],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }
        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[6]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-3];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[6];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[7] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible()&& (*display)[7]->pixmap() ){
            briefMessage->clear();
            if(finalResults != nullptr &&  finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-2],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[7],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }

        }else if(QEvent::Leave==event->type()&& briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[7]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-2];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[7];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    if(  (*display)[8] == watched){
        if(QEvent::Enter==event->type() && !briefMessage->isVisible()&& (*display)[8]->pixmap() ){
            briefMessage->clear();
            if(finalResults != nullptr &&  finalResults->size() > 9){
                labelSetText((*finalResults)[currentIndex-1],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }else if(finalResults != nullptr && finalResults->size() > 0){
                labelSetText((*finalResults)[8],briefMessage);
                briefMessage->setGeometry(x+75,y-20,200,200);
                briefMessage->show();
            }
        }else if(QEvent::Leave==event->type() && briefMessage->isVisible()){
            briefMessage->hide();

        }else if(QEvent::MouseButtonPress == event->type()&& briefMessage->isVisible() && (*display)[8]->pixmap()){
            if( finalResults->size() > 9){
                resultAnimalPage->myAnimal = (*finalResults)[currentIndex-1];
            }else if(finalResults->size() > 0){
                resultAnimalPage->myAnimal = (*finalResults)[8];
            }
            if(this->myAdopter != nullptr){
                double dist = this->searchEngine->getDistanceBetweenAnimalandAdopter(resultAnimalPage->myAnimal, myAdopter);
                string address = this->searchEngine->getShelterAddressByID(resultAnimalPage->myAnimal->getShelterID());
                resultAnimalPage->adopter = myAdopter;
                resultAnimalPage->address = address;
                resultAnimalPage->updateDisplay(dist);
                resultAnimalPage->show();
            }else{
                QMessageBox *m_box;
                m_box = new QMessageBox(QMessageBox::Information,QString("Reminder"),QString("Please Login or Register First!"));
                m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                m_box->exec();
            }
        }
   }
    return QObject::eventFilter(watched,event);
}

void Cat::recevieHideAddressComboBox()
{
    ui->label->setVisible(false);
    ui->comboBoxCities->setVisible(false);
    ui->comboBoxStates->setVisible(false);
    ui->label_2->setVisible(false);
}
void Cat::recevieShowAddressComboBox()
{

    ui->comboBoxCities->setVisible(true);
    ui->label->setVisible(true);
    ui->comboBoxStates->setVisible(true);
    ui->label_2->setVisible(true);
}

vector<Animal *>* Cat::BestMatch(vector<Animal *>* resultAnimals)
{
    resultAnimals->clear();
    finalResults->clear();
    vector<string>* preferences = this->searchEngine->getPreferencesByAdopterID(this->myAdopter->getID());
    if(preferences->size() == 0){
        cout << "you need to fill in preference question first" << endl;
        return resultAnimals;
    }
    currentIndex = 0;
    int change = 0;
    map<int, int >* temp = new map<int,int>();
    vector<Animal*>* breedss;
    vector<Animal*>* genderss;
    vector<Animal*>* agess;
    vector<Animal*>* namess;
    vector<Animal*>* sizess;
    vector<Animal*>* colorss;
    vector<Animal*>* coatLengthss;
    vector<Animal*>* energyLvlss;
    vector<int>* results = new vector<int>();
    string name = ui->lineEdit_name->text().toStdString();
    string species = "Cat";
    string breed = ui->combobox_Breeds->currentText().toStdString();
    string gender = ui->comboBox_Gender->currentText().toStdString();
    string age = ui->combobox_Age->currentText().toStdString();
    string size = ui->comboBox_Size->currentText().toStdString();
    string color = ui->comboBox_Color->currentText().toStdString();
    string coatLength = ui->comboBox_CoatLength->currentText().toStdString();
    string energylvl = ui->comboBox_activeLevel->currentText().toStdString();
//    temp->push_back(energyLevel);
//    temp->push_back(coatLength);
//    temp->push_back(color);
//    temp->push_back(size);
    if(name != ""){
        namess = searchEngine->searchForOneInOneSpecies("Cat","Name", name);
        addToMapHelper(temp,namess);
        change++;
    }
    if( breed != ""){
        breedss =  searchEngine->searchForOneInOneSpecies("Cat","Breed", breed);
        addToMapHelper(temp,breedss);
        change++;
    }
    if(gender != "" ){
        genderss =  searchEngine->searchForOneInOneSpecies("Cat","Gender", gender);
        addToMapHelper(temp,genderss);
        change++;
    }
    if(age != ""){
        agess = searchEngine->searchForOneInOneSpecies("Cat","Age", age);
        addToMapHelper(temp,agess);
        change++;
    }
    if( size != ""){
        sizess = searchEngine->searchForOneInOneSpecies("Cat","Size", size);
        addToMapHelper(temp,sizess);
        change++;
    }else{
        sizess = searchEngine->searchForOneInOneSpecies("Cat","Size", (*preferences)[3]);
        addToMapHelper(temp,sizess);
        change++;
    }
    if( color != ""){
        colorss = searchEngine->searchForOneInOneSpecies("Cat","Color", color);
        addToMapHelper(temp,colorss);
        change++;
    }else{
        colorss = searchEngine->searchForOneInOneSpecies("Cat","Color", (*preferences)[2]);
        addToMapHelper(temp,colorss);
        change++;
    }
    if(coatLength != ""){
        coatLengthss = searchEngine->searchForOneInOneSpecies("Cat","CoatLength", coatLength);
        addToMapHelper(temp,coatLengthss);
        change++;
    }else{
        coatLengthss = searchEngine->searchForOneInOneSpecies("Cat","CoatLength", (*preferences)[1]);
        addToMapHelper(temp,coatLengthss);
        change++;
    }
    if(energylvl != ""){
        energyLvlss = searchEngine->searchForOneInOneSpecies("Cat","EnergyLevel", energylvl);
        addToMapHelper(temp,energyLvlss);
        change++;
    }else{
        energyLvlss = searchEngine->searchForOneInOneSpecies("Cat","EnergyLevel", (*preferences)[0]);
        addToMapHelper(temp,energyLvlss);
        change++;
    }

    for(auto itr = temp->begin(); itr != temp->end(); itr++){
        if(itr->second == change){
            //cout << itr->first << endl;
            results->push_back(itr->first);
        }
    }
    if(results->size()>0){
        cout << "size large than 0" << endl;
        resultAnimals = searchEngine->getAnimalsByIDs(results);
         cout << "size of result Animals"  << resultAnimals->size() << endl;
        finalResults = resultAnimals;
    }else{
        resultAnimals = new vector<Animal*>();
        finalResults = new vector<Animal*>();
    }
    return resultAnimals;
}
