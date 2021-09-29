#ifndef LOGIND_H
#define LOGIND_H
#include "questionaire.h"
#include "regispage.h"
#include <QDialog>
#include <string>
#include <iostream>
#include "../Dam/adopterdam.h"
#include "../Dam/employeedam.h"
using namespace std;
namespace Ui {
class logind;
}

class Logind : public QDialog
{
    Q_OBJECT

public:
    explicit Logind(QWidget *parent = 0);
    ~Logind();
    questionaire *qpage;
    Adopter* myAdopter;
    Employee* myEmployee;
    Adopter* getMyAdopter();
    Employee* getMyEmployee();
    int user; //0 if no info, 1 for Adopter, 2 for Employee
private slots:
    void on_pushButton_LOGIN_clicked();
    void logindReceivesShow();
    void on_pushButton_Register_2_clicked();
    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();
    void on_toolButton_home_clicked();

signals:
    void logindShowmainwindow();
    void logindShowRegister();
    void logindSHowNewMenuWithoutLogin();

private:
    Ui::logind *ui;
  //  void checkusernamematchpw();

};

#endif // LOGIND_H
