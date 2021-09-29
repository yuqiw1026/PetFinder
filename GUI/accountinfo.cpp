#include "accountinfo.h"
#include "ui_accountinfo.h"

AccountInfo::AccountInfo(QWidget *parent, FileReader* fileReader) :
    QWidget(parent),
    ui(new Ui::AccountInfo)
{    
    QWidget *homeWidget = new QWidget;

    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget ->addWidget(homeWidget);

    ui->setupUi(this);

    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QPalette pe;

    pe.setColor(QPalette::WindowText, QColor(0,0,0));
    ui->toolButton->setStyleSheet("QToolButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->pushButton_Home_2->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->comboBox_Language->setStyleSheet("QComboBox{border:0px;background-color:rgb(255,255,255);font-family:'Adobe Gothic Std';font-size:18px;color:rgb(104,86,76);}");
    ui->pushButton->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);font-family:'Adobe Gothic Std';font-size:18px;color:rgb(255,255,255);border-radius:6px;}");
    ui->pushButtonSave->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);font-family:'Adobe Gothic Std';font-size:18px;color:rgb(255,255,255);border-radius:6px;}");
    this->myAdopter = nullptr;
    this->myEmployee = nullptr;
    switchToEdit(false);


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
}

AccountInfo::~AccountInfo()
{
    delete ui;
}

void AccountInfo::on_toolButton_clicked()
{
    this->hide();
    emit accountShowmainwindow();
}

void AccountInfo::accountReceiveshow(){
    this->show();
}

void AccountInfo::updateDisplay()
{
    if(this->myAdopter){
        ui->current_userName->setText(QString::fromStdString(myAdopter->getUserName()));
        ui->current_phoneNo->setText(QString::fromStdString(myAdopter->getPhoneNo()));
        ui->current_email->setText(QString::fromStdString(myAdopter->getEmail()));
        ui->current_gender->setText(QString::fromStdString(myAdopter->getGender()));
        ui->current_age->setText(QString::number(myAdopter->getAge()));
        string address = myAdopter->getAddress();
        vector<string> result;
        stringstream s_stream(address); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            result.push_back(substr);
        }
        ui->current_stateName->setText(QString::fromStdString(result[0]));
        ui->current_cityName->setText(QString::fromStdString(result[1]));

    }else if(this->myEmployee){
        //TODO?
    }
}

void AccountInfo::on_pushButton_clicked()
{
    switchToEdit(true);
}

void AccountInfo::switchToEdit(bool type)
{
    ui->lineEdit_userName->setVisible(type);
    ui->lineEdit_phoneNumber->setVisible(type);
    ui->lineEdit_email->setVisible(type);
    ui->comboBoxCities->setVisible(type);
    ui->comboBoxStates->setVisible(type);
    ui->label->setVisible(type);
    ui->label_5->setVisible(type);
    ui->label_6->setVisible(type);
    ui->lineEdit_currentPasswd->setVisible(type);
    ui->lineEdit_newPasswd->setVisible(type);
    ui->lineEdit_newPasswd2->setVisible(type);
    ui->lineEdit_age->setVisible(type);
    ui->comboBox_gender->setVisible(type);
    ui->pushButtonSave->setVisible(type);


    ui->current_userName->setVisible(!type);
    ui->current_phoneNo->setVisible(!type);
    ui->current_email->setVisible(!type);
    ui->current_stateName->setVisible(!type);
    ui->current_cityName->setVisible(!type);
    ui->current_gender->setVisible(!type);
    ui->current_age->setVisible(!type);

}

void AccountInfo::on_pushButtonSave_clicked()
{
    switchToEdit(false);
    string newUserName = "";
    string newGender = "";
    int  newAge = 0;
    string newPhoneNo= "";
    string newEmail = "";
    string newCity = "";
    string newState = "";

    string currentPasswd = "";
    string newPasswd = "";
    string newPasswd2 = "";
   // if(ui->lineEdit_userName->text().toStdString() != ""){
        newUserName = ui->lineEdit_userName->text().toStdString() ;
    //}
   // if(ui->lineEdit_phoneNumber->text().toStdString() != ""){
       newPhoneNo = ui->lineEdit_phoneNumber->text().toStdString();
    //}
   // if(ui->lineEdit_email->text().toStdString() != ""){
        newEmail = ui->lineEdit_email->text().toStdString();
        newAge = ui->lineEdit_age->text().toInt();
   // }
   // if(ui->lineEdit_currentPasswd->text().toStdString() != ""){
        currentPasswd = ui->lineEdit_currentPasswd->text().toStdString();
   // }
   // if(ui->lineEdit_newPasswd->text().toStdString() != ""){
        newPasswd = ui->lineEdit_newPasswd->text().toStdString();
   // }
    //if(ui->lineEdit_newPasswd2->text().toStdString() != ""){
        newPasswd2 = ui->lineEdit_newPasswd2->text().toStdString();
    //}
       newGender = ui->comboBox_gender->currentText().toStdString();

    //if(ui->comboBoxCities->currentText().toStdString() != ""){
        newCity = ui->comboBoxCities->currentText().toStdString();
    //}
    //if(ui->comboBoxStates->currentText().toStdString() != ""){
        newState = ui->comboBoxStates->currentText().toStdString();
   // }
    if(newUserName != "" || newAge != 0 || newGender != "" || newEmail!= "" ||
            newPhoneNo != "" || newCity != "" || newState != "" ||
            currentPasswd != "" || newPasswd != "" || newPasswd2 != ""){
      int temp = myAdopterDam->updateIndividual(myAdopter,newUserName,newGender,newAge,newPhoneNo,newEmail,currentPasswd, newPasswd, newPasswd2,newCity, newState);
      if(temp == 0){
          QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Wrong Current password!"));
          QTimer::singleShot(2000,m_box,SLOT(accept()));
          m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
          m_box->exec();
      }else if(temp == 2){
          QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Two passwords do not match!"));
          QTimer::singleShot(2000,m_box,SLOT(accept()));
          m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
          m_box->exec();
      }
    }
    updateDisplay();
}


void AccountInfo::on_comboBoxStates_activated(const QString &arg1)
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
 for(unsigned int i = 1; i < resultCities->size() ; i++){
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

void AccountInfo::receivesTranslateToSpanish()
{
    ui->comboBox_Language->setCurrentIndex(0);

    ui->label->setText("Confirmar de nuevo");
    ui->label_2->setText("Información de la cuenta");
    ui->label_3->setText("edad");
    ui->label_5->setText("Nueva contraseña");
    ui->label_6->setText("Contraseña actual");
    ui->label_8->setText("Estatal");
    ui->label_9->setText("Ciudad");
    ui->label_4->setText("Email");
    ui->label_7->setText("la dirección");
    ui->label_10->setText("Nombre de usuario");
    ui->label_11->setText("género");
    ui->label_12->setText("número de teléfono");
    ui->comboBox_Language->setItemText(0,"El lenguaje");
    ui->comboBox_Language->setItemText(1,"el inglés");
    ui->comboBox_Language->setItemText(2,"el español");
    ui->comboBox_gender->setItemText(1,"Mujer");
    ui->comboBox_gender->setItemText(2,"Masculino");
    ui->pushButton_Home_2->setText("Perfil");
    ui->pushButton->setText("Editar");
    ui->pushButtonSave->setText("Ahorrar");

}

//void AccountInfo::receivesTranslateToSpanishC(){
//    receivesTranslateToSpanish();
//}

void AccountInfo::receivesTranslateToEnglish()
{
    ui->comboBox_Language->setCurrentIndex(0);

    ui->label->setText("Confirm again");
    ui->label_2->setText("AccountInfo");
    ui->label_3->setText("Age");
    ui->label_4->setText("Email");
    ui->label_5->setText("New Password");
    ui->label_6->setText("Current Password");
    ui->label_7->setText("Address");
    ui->label_8->setText("State");
    ui->label_9->setText("City");
    ui->label_10->setText("UserName");
    ui->label_11->setText("Gender");
    ui->label_12->setText("Phone Number");
    ui->comboBox_Language->setItemText(0,"Language");
    ui->comboBox_Language->setItemText(1,"English");
    ui->comboBox_Language->setItemText(2,"Spanish");
    ui->comboBox_gender->setItemText(1,"Female");
    ui->comboBox_gender->setItemText(2,"Male");
    ui->pushButton_Home_2->setText("Profile");
    ui->pushButton->setText("Edit");
    ui->pushButtonSave->setText("Save");

}

//void AccountInfo::reveivesTranslateToEnglishC(){
//    reveivesTranslateToEnglish();
//}


void AccountInfo::on_comboBox_Language_currentIndexChanged(int index)
{
    if(index == 1){
        receivesTranslateToEnglish();
        emit translateToEnglish();
    }else if(index == 2){
        receivesTranslateToSpanish();
        emit translateToSpanish();
    }
}
