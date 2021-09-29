#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <QWidget>
#include <QtWidgets>
#include <QStackedWidget>
#include "../DataBase/UserInfo/adopter.h"
#include "../DataBase/UserInfo/employee.h"
#include "../Dam/adopterdam.h"
#include "../DataBase/Location/filereader.h"
#include <iostream>
#include <sstream>
#include <QMessageBox>
using namespace std;
namespace Ui {
class AccountInfo;
}

class AccountInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AccountInfo(QWidget *parent = nullptr, FileReader* fileReader = nullptr);
    ~AccountInfo();
    Adopter* myAdopter;
    Employee* myEmployee;
    AdopterDam* myAdopterDam;
    FileReader* fileReader;
    void updateDisplay();

private slots:

    void on_toolButton_clicked();

    void accountReceiveshow();

    void on_pushButton_clicked();

    void on_pushButtonSave_clicked();

    void on_comboBoxStates_activated(const QString &arg1);

    void receivesTranslateToSpanish();

    void receivesTranslateToEnglish();

    void on_comboBox_Language_currentIndexChanged(int index);

signals:
    void accountShowmainwindow();
    void translateToSpanish();
    void translateToEnglish();

private:
    Ui::AccountInfo *ui;
    void switchToEdit(bool type);
};

#endif // COMMUNITYPAGE_H
