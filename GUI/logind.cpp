#include "logind.h"
#include "ui_logind.h"
#include "regispage.h"

Logind::Logind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logind)
{
    ui->setupUi(this);
    this->setFixedSize(560,500);
    QPixmap bkgnd(":imgs/Kuang2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->setWindowTitle("Login");
    ui->label_message->setVisible(false);
    ui->toolButton_home->setFixedWidth(120);
    ui->pushButton_Register_2->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->pushButton_LOGIN->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    this->myAdopter = NULL;
    user = 0;
}

Logind::~Logind()
{
    delete ui;
}
/*
void logind::checkusernamematchpw()
{
check=true;
}
*/
void Logind::on_pushButton_LOGIN_clicked()
{
    string userName = ui->inPutName->text().toStdString();
    string passWd = ui->inPutPw->text().toStdString();
    string userType = ui->comboBoxUserType->currentText().toStdString();


    if(userType == "Adopter" || userType == "Adoptante"){
        AdopterDam* adopterDam = new AdopterDam();
        int result = adopterDam->loggin(userName,passWd);
        if( result == 2){
            myAdopter = adopterDam->getAdopterByName(userName);
            user = 1;
            this->hide();
            emit logindShowmainwindow();
        }else if(result == 1){
             ui->label_message->setVisible(true);
            ui->label_message->setText("No Such User!");

        }else if(result == 0){
             ui->label_message->setVisible(true);
            ui->label_message->setText("Wrong Password!");
         }
    }

    else if(userType == "Employee" || userType == "Empleado"){
       EmployeeDam* employeeDam = new EmployeeDam();
               // employeeDam->read();
                int result = employeeDam->login(userName,passWd);
                cout << result << endl;

                if( result == 2){
                    myEmployee = employeeDam->getEmployeeByName(userName);
                    user = 2;
                    this->hide();
                    emit logindShowmainwindow();
                }else if(result == 1){
                     ui->label_message->setVisible(true);
                    ui->label_message->setText("No Such User!");

                }else if(result == 0){
                     ui->label_message->setVisible(true);
                    ui->label_message->setText("Wrong Password!");
                 }

    }else{
        cout << "User Type Error" << endl;
    }
}

void Logind::on_pushButton_Register_2_clicked()
{
    this->hide();
    emit logindShowRegister();
}

Adopter* Logind::getMyAdopter()
{
    if(this->myAdopter != NULL){
        return this->myAdopter;
    }
    return NULL;
}
Employee* Logind::getMyEmployee(){
    if(this->myEmployee != NULL){
           return this->myEmployee;
       }
       return NULL;

}
void Logind::logindReceivesShow()
{
    this->show();
}


void Logind::receivesTranslateToSpanish(){
    ui->comboBoxUserType->setItemText(0,"- Seleccione el tipo de usuario");
    ui->comboBoxUserType->setItemText(1,"Adoptante");
    ui->comboBoxUserType->setItemText(2,"Empleado");
    ui->label_Username_2->setText("Nombre de usuario");
    ui->label_Password_2->setText("Contraseña");
    ui->pushButton_LOGIN->setText("ACCESO");
    ui->label_message->setText("Iniciar sesiónMensaje");
    ui->label_1->setText("¿Aún no tienes una cuenta? ¡Registrar aquí!");
    ui->pushButton_Register_2->setText("Registrarse");
}

void Logind::receivesTranslateToEnglish(){
   ui->comboBoxUserType->setItemText(0,"--Please select user type");
   ui->comboBoxUserType->setItemText(1,"Adopter");
   ui->comboBoxUserType->setItemText(2,"Employee");
   ui->label_Username_2->setText("Username");
   ui->label_Password_2->setText("Password");
   ui->pushButton_LOGIN->setText("LOGIN");
   ui->label_message->setText("LoginMessage");
   ui->label_1->setText("Don't have an account yet? Register here!");
   ui->pushButton_Register_2->setText("Register");
}


void Logind::on_toolButton_home_clicked()
{
    this->hide();
    emit logindSHowNewMenuWithoutLogin();
}
