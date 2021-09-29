#ifndef NEWMENU_H
#define NEWMENU_H
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <QApplication>
#include <iostream>
#include "../GUI/cat.h"
#include "../GUI/dog.h"
#include "../GUI/other.h"
#include "../GUI/logind.h"
#include "../GUI/questionaire.h"
#include "../GUI/aboutpage.h"
#include "../GUI/mypreference.h"
#include "../GUI/communitypage.h"
#include "../GUI/aftersignout.h"
#include "../GUI/animalinfos.h"
#include "../GUI/adopterorder.h"
#include "../GUI/employeeorder.h"
#include "../DataBase/UserInfo/adopter.h"
#include "../DataBase/UserInfo/employee.h"
#include "../GUI/adopterorder.h"
using namespace std;
namespace Ui {
class NewMenu;
}

class NewMenu : public QWidget
{
    Q_OBJECT

public:
    explicit NewMenu(QWidget *parent = nullptr);
    ~NewMenu();
    //void dealwindow2();
   // questionaire *qpage;
    Other *new_rabbit;
    CommunityPage *cpage;
    Aftersignout* userSignOutPage;
    AccountInfo* accountInfoPage;
    AnimalInfos* anmInfoPage;
    Cat* catPage;
    Dog* dogPage;
    Other* otherPage;
    Logind* logindPage;
    bool ifLogin=false;
    Adopter* adopter;
    Employee* employee;
    adopterorder* adopterOderPage;
    employeeorder* employeeOrderPage;
    mypreference* myPrefPage;


    int User;
    int petType = 0;
    int lanType = 0;
    void updatedisplay();
    bool eventFilter(QObject *watched, QEvent *event);
private slots:

    void on_pushButton_login_2_clicked();

    void on_pushButtonCat_clicked();

    void on_pushButtonDog_clicked();

    // void on_pushButtonOtherPets_clicked();
    //void on_pushButtonLanguage_4_windowIconChanged(const QIcon &icon);

    void on_pushButtonCommunity_4_clicked();
    void on_pushButtonAbout_4_clicked();

    //switch functions
//    void receiveCommunity();
//    void receiveCat();
//    void receiveDog();
      void receiveLogind();
//    void receiveAbout();
//    void receivePref();
//    void receiveOther();
//    void receiveAccount();
    void newMenueReceivesShow();

    // void receiveWl();

   // void on_comboBox_afterlogin_currentIndexChanged(int index);

    void on_pushButtonOtherPets_clicked();

    void on_comboBox_afterlogin_activated(int index);

    void on_Language_5_currentTextChanged(const QString &arg1);
    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();

//    void receivesTranslateToSpanishNM();
//    void receivesTranslateToEnglishNM();

    void on_comboBox_afteremployeelogin_activated(int index);

signals:
    void comshow();
    void catshow();
    void dogshow();
    void logindShow();
    void aboutshow();
    void prefshow();
    void wishlistshow();
    void othershow();
    void accountshow();
    void adopterordershow();
    void employeeordershow();
    void anminfoshow();
    void translateToSpanish();
    void translateToEnglish();
    void hideAddressComboBox();
    void reShowAddressComboBox();

private:
    Ui::NewMenu *ui;
    void checklogin();
};

#endif // NEWMENU_H
