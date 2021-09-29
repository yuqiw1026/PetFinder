#ifndef REGISPAGE_H
#define REGISPAGE_H

#include <QDialog>
#include "../Dam/adopterdam.h"
#include "../Dam/employeedam.h"
#include "../DataBase/Location/filereader.h"
#include <string>
#include <QCompleter>
#include <QMessageBox>
#include <QRegExpValidator>

using namespace std;
namespace Ui {
class Regispage;
}

class Regispage : public QDialog
{
    Q_OBJECT

public:
    explicit Regispage(QWidget *parent = 0, FileReader* fileReader = nullptr);
    ~Regispage();
    AdopterDam* myAdopterDam;
    EmployeeDam* myEmployeeDam;
    FileReader* fileReader;
    int regisLan = 0;
private slots:
    //void on_pushButton_clicked();
    void on_signButton_clicked();
    void registerReceivesShow();
    void on_comboBoxStates_activated(const QString &arg1);

    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();
    void on_pushButtonBack_clicked();

    void on_inputAge_editingFinished();

signals:
    void registerShowLogind();
    void registerShowNewMenue();

private:
    Ui::Regispage *ui;

};

#endif // REGISPAGE_H
