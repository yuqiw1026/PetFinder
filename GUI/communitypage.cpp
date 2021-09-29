#define CUSTOMTOOLBUTTON_H

#include "communitypage.h"
#include "ui_communitypage.h"
#include <QToolButton>
#include <QDebug>
#include <QtGui>
#include "QScrollBar"



CommunityPage::CommunityPage(QWidget *parent, SearchEngine* searchEngine) :
    QWidget(parent),
    ui(new Ui::CommunityPage)
{
    QWidget *homeWidget = new QWidget;
    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget ->addWidget(homeWidget);

    ui->setupUi(this);

    ui->comboBox_Language->setCurrentIndex(0);
    QPixmap bkgnd(":imgs/Preference2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->scrollArea_3->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_4->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_3->setBackgroundRole(QPalette::Mid);
    ui->scrollArea_4->setBackgroundRole(QPalette::Shadow);
    ui->scrollArea_3->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
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
    ui->scrollArea_4->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
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
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_post->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    ui->pushButton_Main->setStyleSheet("QPushButton{border:0px;background-color:rgb(254,191,138);border-radius:6px;}");
    setWindowTitle("Community");
    this->myAdopter = nullptr;
    this->searchEngine = searchEngine;
}

CommunityPage::~CommunityPage()
{
    delete ui;
}

void CommunityPage::on_pushButton_Upvote_clicked()
{
    if(this->myAdopter != nullptr){
        this->searchEngine->likeThePost((*posts)[current]);
        updatePosts();
    }else{
        QMessageBox *m_box;
        m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Please Login First!"));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
    }
}

void CommunityPage::on_pushButton_post_clicked()
{
    if(this->myAdopter != nullptr){
    NewPost* new_p = new NewPost;
    new_p->mySearchEngine = searchEngine;
    new_p->adopterID = myAdopter->getID();
    new_p->show();
    }else{
        QMessageBox *m_box;
        m_box = new QMessageBox(QMessageBox::Information,QString("Warning"),QString("Please Login First!"));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->setStyleSheet("background-color: rgb(255, 255, 255);");
        m_box->exec();
    }
}

void CommunityPage::on_pushButton_Main_clicked()
{
    this->hide();
    emit comShowmainwindow();
}

void CommunityPage::comReceiveshow(){
    updatePosts();
    this->show();
}

void CommunityPage::on_toolButton_clicked()
{
    new_account = new AccountInfo;
    new_account->show();
}

void CommunityPage::receivesTranslateToSpanish(){
    ui->comboBox_Language->setCurrentIndex(0);
    ui->label->setText("Comunidad");
    ui->pushButton_post->setText("Correo");
    ui->comboBox_Language->setItemText(0,"El lenguaje");
    ui->comboBox_Language->setItemText(1,"el inglés");
    ui->comboBox_Language->setItemText(2,"el español");
}

void CommunityPage::receivesTranslateToEnglish(){
    ui->comboBox_Language->setCurrentIndex(0);
    ui->label->setText("Community");
    ui->pushButton_post->setText("Post");
    ui->comboBox_Language->setItemText(0,"Language");
    ui->comboBox_Language->setItemText(1,"English");
    ui->comboBox_Language->setItemText(2,"Spanish");
}

void CommunityPage::on_comboBox_Language_currentIndexChanged(int index)
{
    if(index == 1){
        receivesTranslateToEnglish();
        emit translateToEnglish();
    }else if(index == 2){
        receivesTranslateToSpanish();
        emit translateToSpanish();
    }
}
void CommunityPage::updatePosts()
{
    this->posts = this->searchEngine->getAllPosts();
    if(current < posts->size() && current >= 0){
    Post* post = (*posts)[current];
    this->ui->textEdit->setText(QString::fromStdString(post->context));
    this->ui->label_userName->setText( QString::fromStdString(this->searchEngine->getAdopterNameByID(post->adopterID)));
    this->ui->label_numOfLikes->setText(QString::fromStdString(to_string(post->likeNum)));
    //TODO
    if(post->fileName != ""){
    QString::fromStdString("" + post->fileName);
    QString picLocation = QString::fromStdString("../../../../DataBase/Pictures/" +  post->fileName);
    ui->label_pic->setPixmap(picLocation);
    }
    }

}

void CommunityPage::on_pushButton_2_clicked()
{
    if(current - 1 >= 0){
        this->current--;

    }
    updatePosts();

}

void CommunityPage::on_pushButton_clicked()
{
    if(current + 1 < posts->size()){
        this->current++;
    }
     updatePosts();
}
