#ifndef CAT_H
#define CAT_H

#include <QDialog>
#include <QWidget>
#include "location.h"
#include <QPushButton>
#include "../DataBase/Location/filereader.h"
#include "../DataBase/searchengine.h"
#include <QStringList>
#include <QCompleter>
#include <QMessageBox>
#include "../GUI/resultanimal.h"
using namespace std;
namespace Ui {
class Cat;
}

class Cat : public QDialog
{
    Q_OBJECT

public:
    explicit Cat(QWidget *parent = nullptr, FileReader* = nullptr, SearchEngine* searchEngine = nullptr, ResultAnimal* resultAnimalPage = nullptr);
    ~Cat();
    //MainWindow *mainpage;
    FileReader* fileReader;
    SearchEngine* searchEngine;
    vector<QLabel*>* display;
    vector<Animal*>* finalResults;
    vector<double>* finalDistances;
    int currentIndex;
    QLabel* briefMessage;
    ResultAnimal* resultAnimalPage;
     bool eventFilter(QObject *watched, QEvent *event);
     Adopter* myAdopter;
     vector<Animal *>* BestMatch(vector<Animal*>* resultAnimals);
public slots:
   // void on_pushButton_ToMain_clicked();


private slots:


    void catReceiveshow();

    void on_toolButton_home_clicked();

    void on_comboBoxStates_activated(const QString &arg1);

    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();

    void on_comboBox_CatLanguage_currentIndexChanged(int index);

    void on_pushButton_search_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_pre_clicked();

    void recevieHideAddressComboBox();
    void recevieShowAddressComboBox();

private:
    Ui::Cat *ui;

signals:
    void catShowmainwindow();
    void anmresltshow();
    void translateToSpanish();
    void translateToEnglish();
};



#endif // CAT_H
