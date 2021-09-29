#include "newpost.h"
#include "ui_newpost.h"

NewPost::NewPost(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPost)
{
    ui->setupUi(this);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setWindowTitle("New Post");
    ui->pushButton_post->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    this->adopterID = -1;
    this->mySearchEngine = nullptr;
}

NewPost::~NewPost()
{
    delete ui;
}

void NewPost::receivesTranslateToSpanish(){
    ui->label_home1->setText("Casa");
    ui->pushButton_post->setText("Correo");
}

void NewPost::receivesTranslateToEnglish(){
    ui->label_home1->setText("Home");
    ui->pushButton_post->setText("Post");
}

void NewPost::on_pushButton_post_clicked()
{
   std::string text = this->ui->textEdit_main->toPlainText().toStdString();
   std::string fileName = this->ui->lineEdit_fileName->text().toStdString();
    if(text != "" && this->adopterID != -1){
        this->mySearchEngine->addNewPost(this->adopterID, text,fileName,0 );
        this->close();
    }
}
