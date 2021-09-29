#include "newmenu.h"
#include "ui_newmenu.h"
NewMenu::NewMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewMenu)
{
    ui->setupUi(this);
    this->setFixedSize(800,1200);
    // this->setStyleSheet("background-color:rgb(254,231,214);}");
    //light orange rgb(254,231,214);
    //this->setStyleSheet("background-image:url(\":imgs/Main3.jpg\"); background-position: center;" );//按钮背景会变成图片（挺好看的）
    QPixmap bkgnd(":imgs/Mainpart2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    QPalette   pal;
    pal.setColor(QPalette::ButtonText, QColor(255,255,255));
    ui->pushButtonCat->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);border-radius:6px;}");
    ui->pushButtonCat->setPalette(pal);
    ui->pushButtonDog->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);border-radius:6px;}");
    ui->pushButtonDog->setPalette(pal);
    ui->pushButtonOtherPets->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);border-radius:6px;}");
    ui->pushButtonOtherPets->setPalette(pal);
    //ui->pushButtonSearch->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,139);}");
    //ui->pushButtonSearch->setPalette(pal);
    ui->pushButton_login_2->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,231,214);}");
    //     ui->Get_2->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,231,214);}");
    // ui->pushButtonPetFinder_4->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);}");
    ui->pushButtonCommunity_4->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);border-radius:6px;}");
    ui->pushButtonCommunity_4->setPalette(pal);
    ui->pushButtonAbout_4->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);border-radius:6px;}");
    ui->pushButtonAbout_4->setPalette(pal);
    ui->pushButtonLanguage->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);border-radius:6px;}");
    ui->pushButtonLanguage->setPalette(pal);
    //ui->pushButtonSearch->setStyleSheet("QPushButton{border:0px;background-color:rgb(104,86,76);}");
    User = 0;
    ui->comboBox_afterlogin->setVisible(false);
    ui->comboBox_afteremployeelogin->setVisible(false);
    ui->label_welcome->setVisible(false);
    setWindowTitle("PetFinder");
    ui->pushButtonCat->installEventFilter(this);
    ui->pushButtonDog->installEventFilter(this);
    ui->pushButtonOtherPets->installEventFilter(this);
}
NewMenu::~NewMenu()
{
    delete ui;
}
void NewMenu::on_pushButton_login_2_clicked()
{
    this->hide();
   emit logindShow();
}
void NewMenu::on_pushButtonCat_clicked()
{
    this->hide();
    emit catshow();
}
void NewMenu::on_pushButtonDog_clicked()
{
    this->hide();
    emit dogshow();
}
void NewMenu::on_pushButtonOtherPets_clicked()
{
    this->hide();
    emit othershow();
}
void NewMenu::on_pushButtonAbout_4_clicked()
{
    this->hide();
    emit aboutshow();
}
void NewMenu::on_pushButtonCommunity_4_clicked()
{
    this->hide();
    emit comshow();
}
//void NewMenu::receiveCommunity(){
//    this->show();
//}
//void NewMenu::receiveCat(){
//    this->show();
//}
//void NewMenu::receiveDog(){
//    this->show();
//}
//void NewMenu::receiveOther(){
//    this->show();
//}
void NewMenu::newMenueReceivesShow()
{
    updatedisplay();
    this->show();
}

void NewMenu::updatedisplay(){

    if(ifLogin){
         string temp;
        ui->pushButton_login_2->setVisible(false);
        ui->label_welcome->setVisible(true);

        if(this->logindPage->user == 1){
          ui->comboBox_afterlogin->setVisible(true);
          temp = this->logindPage->myAdopter->getUserName();
        }else if(this->logindPage->user == 2){
          ui->comboBox_afteremployeelogin->setVisible(true);
          temp = this->logindPage->myEmployee->getUserName();
        }
        if(lanType == 0){
        temp = "Welcome Back! " + temp;
        }else if(lanType == 1){
        temp = "Bienvenido de vuelta! " + temp;
        }
         ui->label_welcome->setText(QString::fromStdString(temp));
        if(logindPage->user == 1){
            this->adopter = logindPage->myAdopter;
            this->accountInfoPage->myAdopter = this->adopter;
            this->catPage->myAdopter = this->adopter;
            this->accountInfoPage->updateDisplay();
            this->adopterOderPage->myAdopter = this->adopter;
            this->myPrefPage->myAdopter = this->adopter;
            this->cpage->myAdopter = this->adopter;
            emit hideAddressComboBox();
        }else if(logindPage->user == 2){
            this->employee = logindPage->myEmployee;
            this->accountInfoPage->myEmployee = this->employee;
            this->employeeOrderPage->myEmployee = this->employee;
        }
    }else{
        ui->pushButton_login_2->setVisible(true);
        ui->comboBox_afterlogin->setVisible(false);
    }
}
void NewMenu::receiveLogind()
{
    this->show();
    ifLogin = true;
    updatedisplay();
}
//void NewMenu::receiveAbout()
//{
//    this->show();
//}
//void NewMenu::receivePref(){
//    ui->comboBox_afterlogin->setCurrentIndex(0);
//    this->show();
//}
//void NewMenu::receiveAccount(){
//    ui->comboBox_afterlogin->setCurrentIndex(0);
//    this->show();
//}
bool NewMenu::eventFilter(QObject *watched, QEvent *event)
{
    if(ui->pushButtonCat==watched){
        petType = 1;
        ui->labelImage->setPixmap(QPixmap(":/imgs/MainKitten3.jpg"));
        ui->labelImage->setFixedHeight(300);
        ui->labelImage->setFixedWidth(564);
    }
    if(ui->pushButtonDog==watched){
        petType = 2;
        ui->labelImage->setPixmap(QPixmap(":/imgs/MainDoge3.jpg"));
        ui->labelImage->setFixedHeight(300);
        ui->labelImage->setFixedWidth(564);
    }
    if(ui->pushButtonOtherPets == watched){
        petType = 3;
        ui->labelImage->setPixmap(QPixmap(":/imgs/MainOther3.jpg"));
        ui->labelImage->setFixedHeight(300);
        ui->labelImage->setFixedWidth(564);
    }
    return QObject::eventFilter(watched,event);
}
void NewMenu::on_comboBox_afterlogin_activated(int index)
{
    if(index == 0){
    }else if(index == 1){
        ui->comboBox_afterlogin->setCurrentIndex(0);
        this->hide();
        emit accountshow();
    }else if(index == 2){
        ui->comboBox_afterlogin->setCurrentIndex(0);
        this->hide();
        emit prefshow();
     }else if(index == 3){
        ui->comboBox_afterlogin->setCurrentIndex(0);
        this->hide();
        emit adopterordershow();
    }else if(index == 4){
        ui->comboBox_afterlogin->setVisible(false);
         QMessageBox *m_box;
        if(lanType == 0){
            m_box = new QMessageBox(QMessageBox::Information,QString("SignOut"),QString("Signout Successfully"));
        }else if(lanType == 1){
            m_box = new QMessageBox(QMessageBox::Information,QString("desconectar"),QString("Cerrar sesión correctamente"));
        }
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();

        /*
         userSignOutPage = new Aftersignout;
         userSignOutPage->show();
         */

         if(this->adopter){
             this->adopter = NULL;
             this->accountInfoPage->myAdopter = NULL;
             this->adopterOderPage->myAdopter = nullptr;
             this->myPrefPage->myAdopter = nullptr;
             this->cpage->myAdopter = nullptr;
             this->catPage->myAdopter = nullptr;
             emit reShowAddressComboBox();

        }else if(this->employee){
            this->employee = NULL;
            this->accountInfoPage->myEmployee = NULL;
             this->employeeOrderPage->myEmployee = nullptr;
        }
         ui->label_welcome->setVisible(false);
        this->ifLogin = false;
        updatedisplay();
        ui->comboBox_afterlogin->setCurrentIndex(0);
    }
}
void NewMenu::on_Language_5_currentTextChanged(const QString &arg1)
{
    if(arg1.toStdString() == "Spanish"){
        receivesTranslateToSpanish();
        emit translateToSpanish();
    }else if(arg1.toStdString() == "English"){
        receivesTranslateToEnglish();
        emit translateToEnglish();
    }
}
void NewMenu::receivesTranslateToSpanish()
{
    lanType = 1;
    ui->Language_5->setCurrentIndex(1);
    ui->pushButtonCat->setText("Gata");
    ui->pushButtonDog->setText("Perro");
    ui->pushButtonOtherPets->setText("otras mascotas");
    ui->pushButtonAbout_4->setText("Acerca de la adopción");
    ui->pushButtonCommunity_4->setText("La comunidad");
    ui->pushButtonLanguage->setText("El lenguaje");
    ui->pushButton_login_2->setText("Registro/inicio");
    ui->comboBox_afterlogin->setItemText(0,"Configuración de la cuenta");
    ui->comboBox_afterlogin->setItemText(1,"Información personal");
    ui->comboBox_afterlogin->setItemText(2,"Mis preferencias");
    ui->comboBox_afterlogin->setItemText(3,"Mi lista de deseos");
    ui->comboBox_afterlogin->setItemText(4,"cancelación");
//    ui->Language_5->setItemText(0,"el inglés");
//    ui->Language_5->setItemText(1,"el español");
    updatedisplay();

}
void NewMenu::receivesTranslateToEnglish()
{
    lanType = 0;
    ui->Language_5->setCurrentIndex(0);
    ui->pushButtonCat->setText("Cat");
    ui->pushButtonDog->setText("Dog");
    ui->pushButtonOtherPets->setText("OtherPets");
    ui->pushButtonAbout_4->setText("About Pet Adoption");
    ui->pushButtonCommunity_4->setText("Community");
    ui->pushButtonLanguage->setText("Language");
    ui->pushButton_login_2->setText("Login/Register");
    ui->comboBox_afterlogin->setItemText(0,"Account settings");
    ui->comboBox_afterlogin->setItemText(1,"Personal Information");
    ui->comboBox_afterlogin->setItemText(2,"My Preferences");
    ui->comboBox_afterlogin->setItemText(3,"My Wishlist");
    ui->comboBox_afterlogin->setItemText(4,"Log out");
//    ui->Language_5->setItemText(0,"English");
//    ui->Language_5->setItemText(1,"Spanish");
    updatedisplay();
}

//void NewMenu::receivesTranslateToSpanishNM(){
//    receiveTranslateToSpanish();
//}

//void NewMenu::receivesTranslateToEnglishNM(){
//    receiveTranslateToEnglish();
//}


void NewMenu::on_comboBox_afteremployeelogin_activated(int index)
{
        if(index == 0){
        }else if(index == 1){
            ui->comboBox_afteremployeelogin->setCurrentIndex(0);
            this->hide();
            emit accountshow();
        }else if(index == 2){
            ui->comboBox_afteremployeelogin->setCurrentIndex(0);
            this->hide();
            emit anminfoshow();
         }else if(index == 3){
            ui->comboBox_afteremployeelogin->setCurrentIndex(0);
            this->hide();
            emit employeeordershow();

        }else if(index==4){
             QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("SignOut"),QString("Signout Successfully"));
             QTimer::singleShot(2000,m_box,SLOT(accept()));
             m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
             m_box->exec();
             this->employee = NULL;
             this->accountInfoPage->myEmployee = NULL;
             ui->label_welcome->setVisible(false);
             ui->comboBox_afteremployeelogin->setVisible(false);
            this->ifLogin = false;
            updatedisplay();
            ui->comboBox_afteremployeelogin->setCurrentIndex(0);
        }

}
