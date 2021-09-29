#ifndef MYPREFERENCE_H
#define MYPREFERENCE_H

#include <QWidget>
#include <string>
#include <QMessageBox>
#include <QTimer>
#include "../DataBase/searchengine.h"
namespace Ui {
class mypreference;
}

using namespace std;
class mypreference : public QWidget
{
    Q_OBJECT

public:
    explicit mypreference(QWidget *parent = 0, SearchEngine* searchEngine = nullptr);
    ~mypreference();
    SearchEngine* mySearchEngine;
    Adopter* myAdopter;
private slots:

    void on_toolButton_home_clicked();
    void prefReceivesshow();

    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();
    void on_comboBox_Language_currentIndexChanged(int index);

    void on_pushButton_Search_clicked();

private:
    Ui::mypreference *ui;

signals:
    void prefShowmainwindow();
    void translateToSpanish();
    void translateToEnglish();

};

#endif // MYPREFERENCE_H
