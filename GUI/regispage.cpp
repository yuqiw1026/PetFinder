#include "regispage.h"
#include "ui_regispage.h"

Regispage::Regispage(QWidget *parent, FileReader* fileReader) :
    QDialog(parent),
    ui(new Ui::Regispage)
{
    ui->setupUi(this);
   // this->setStyleSheet("background-color:rgb(255,255,255);}");
    this->setFixedSize(880,1000);
    QPixmap bkgnd(":imgs/Kuang2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->setWindowTitle("Register");
    ui->signButton->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");

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
//set age input validation
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
ui->inputAge->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,1}")));
ui->inputPhoneNo->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{9}")));
ui->inputEmail->setValidator(new QRegularExpressionValidator(rx,this));
//ui->inputAge->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*")));



}

Regispage::~Regispage()
{
    delete ui;
}
/*
void Regispage::on_pushButton_clicked()
{
    this->hide();
}
*/
void Regispage::on_signButton_clicked()
{
    string userName = ui->inputUserName->text().toStdString();
    string pw1 = ui->inputPw1->text().toStdString();
    string pw2 = ui->inputPw2->text().toStdString();
    int age;

    if(ui->inputAge->hasAcceptableInput()){
            age = ui->inputAge->text().toInt();
       }else{
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Input error"),QString("Please enter a valid age."));
    m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
    m_box->exec();
    }

    string gender = ui->comboBox_gender->currentText().toStdString();
    string phoneNo = ui->inputPhoneNo->text().toStdString();

    string email;
     if(ui->inputAge->hasAcceptableInput()){
    email = ui->inputEmail->text().toStdString();
     }else{
         QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Input error"),QString("Please enter a email address."));
         m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
         m_box->exec();
         }

    string state = ui->comboBoxStates->currentText().toStdString();
    string city = ui->comboBoxCities->currentText().toStdString();
    string address = city + "," + state;

    if(pw1 == pw2){
        if(myAdopterDam->addNewAdopter(pw1,userName,gender,age,phoneNo,email,"Good",address)){
            this->hide();
            emit registerShowLogind();
        }else{
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("UserName has been used!"));
            if(regisLan == 1){
                m_box = new QMessageBox(QMessageBox::Information,QString("Advertencia"),QString("¡Se ha utilizado el nombre de usuario!"));
            }
            QTimer::singleShot(2000,m_box,SLOT(accept()));
            m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
            m_box->exec();
        }
    }else{
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Two passwords do not match!"));
        if(regisLan == 1){
            m_box = new QMessageBox(QMessageBox::Information,QString("Advertencia"),QString("¡Dos contraseñas no coinciden!"));
        }
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
    }
}

void Regispage::registerReceivesShow()
{
    this->show();
}
void Regispage::on_comboBoxStates_activated(const QString &arg1)
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

void Regispage::on_pushButtonBack_clicked()
{
    this->hide();
    emit registerShowNewMenue();
}

void Regispage::receivesTranslateToSpanish(){

    QLineEdit * LINE = new QLineEdit();
    //LINE->setStyleSheet("border:none;font-size:26px;font-weight:bold;color:#5f666e;background:transparent;");
    LINE->setPlaceholderText("Primero elija un estado");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    regisLan = 1;
    ui->label_Username_7->setText("Nombre de usuario");
    ui->label_Password_4->setText("Contraseña");
    ui->label_Password_5->setText("Confirma tu contraseña");
    ui->label_Username_8->setText("Edad");
    ui->comboBox_gender->setItemText(0,"--Por favor seleccione su género");
    ui->comboBox_gender->setItemText(1,"Masculino");
    ui->comboBox_gender->setItemText(2,"Mujer");
    ui->comboBox_gender->setItemText(3,"Otro");
    ui->label_Username_9->setText("Teléfono");
    ui->label_Username_10->setText("Correo electrónico");
    ui->label_Username_11->setText("Habla a");
    ui->label_2->setText("Expresar");
    ui->label->setText("Ciudad");
    ui->textBrowser_2->setText("Al enviar este formulario, acepto recibir comunicaciones de marketing y otras comunicaciones de Petfinder. Lea la Política de privacidad y Acerca de nuestros anuncios.");
    ui->pushButtonBack->setText("¿Vacilación? ¡Navegue primero!");
    ui->signButton->setText("Inscribirse");
}

void Regispage::receivesTranslateToEnglish(){

    QLineEdit * LINE = new QLineEdit();
    LINE->setPlaceholderText("Please choose a state first");
    LINE->setReadOnly(true);
    ui->comboBoxCities->setLineEdit(LINE);

    regisLan = 0;
    ui->label_Username_7->setText("Username");
    ui->label_Password_4->setText("Password");
    ui->label_Password_5->setText("Comfirm your password");
    ui->label_Username_8->setText("Age");
    ui->comboBox_gender->setItemText(0,"--Please select your gender");
    ui->comboBox_gender->setItemText(1,"Male");
    ui->comboBox_gender->setItemText(2,"Female");
    ui->comboBox_gender->setItemText(3,"Other");
    ui->label_Username_9->setText("Telephone");
    ui->label_Username_10->setText("Email");
    ui->label_Username_11->setText("Address");
    ui->label_2->setText("State");
    ui->label->setText("City");
    ui->textBrowser_2->setText("By submitting this form, I agree to receive marketing and other communications from Petfinder. Read the Privacy Policy and About Our Ads.");
    ui->pushButtonBack->setText("Hesitation? Browse First!");
    ui->signButton->setText("Sign Up");
}

void Regispage::on_inputAge_editingFinished()
{
    /*if(!ui->inputAge->hasAcceptableInput()){
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("Input error"),QString("Please enter a valid age."));
                  m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
                  m_box->exec();
    }else{
        ui->inputAge->setText("1");
    }*/

}
