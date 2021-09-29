#ifndef DOG_H
#define DOG_H

#include <QDialog>
#include <QWidget>
#include "location.h"
#include <QPushButton>
#include "../DataBase/Location/filereader.h"
#include "../DataBase/searchengine.h"
#include <QStringList>
#include <QCompleter>

namespace Ui {
class Dog;
}

class Dog : public QDialog
{
    Q_OBJECT


public:
    explicit Dog(QWidget *parent = nullptr, FileReader* = nullptr, SearchEngine* searchEngine = nullptr);
    ~Dog();
    FileReader* fileReader;
    SearchEngine* searchEngine;

private slots:
    void dogReceiveshow();

    void on_toolButton_home_clicked();
    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();

    void on_comboBox_DogLanguage_currentIndexChanged(int index);

    void on_comboBoxStates_activated(const QString &arg1);

signals:
    void dogShowmainwindow();
    void translateToSpanish();
    void translateToEnglish();

private:
    Ui::Dog *ui;
};

#endif // DOG_H
