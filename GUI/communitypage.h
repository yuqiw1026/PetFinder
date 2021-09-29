#ifndef COMMUNITYPAGE_H
#define COMMUNITYPAGE_H

#include <QWidget>
#include <QtWidgets>
#include <QStackedWidget>
#include "newpost.h"
#include "accountinfo.h"
#include "../DataBase/UserInfo/adopter.h"
#include <QMessageBox>
#include <QTimer>
namespace Ui {
class CommunityPage;
}

class CommunityPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommunityPage(QWidget *parent = 0, SearchEngine* searchEngine = nullptr);
    ~CommunityPage();
    NewPost *new_p;
    AccountInfo *new_account;
    Adopter* myAdopter;
    SearchEngine* searchEngine;
    vector<Post*>* posts;
    int current = 0;

private slots:

    void on_pushButton_Upvote_clicked();

    void on_pushButton_post_clicked();

    //switch function
    void comReceiveshow();

    void on_pushButton_Main_clicked();

    void on_toolButton_clicked();

    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();

    void on_comboBox_Language_currentIndexChanged(int index);
    void updatePosts();
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void comShowmainwindow();
    void translateToSpanish();
    void translateToEnglish();

private:
    Ui::CommunityPage *ui;
};

#endif // COMMUNITYPAGE_H
