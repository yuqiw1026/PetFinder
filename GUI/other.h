#ifndef OTHER_H
#define OTHER_H

#include <QDialog>
#include <QWidget>
#include "location.h"
#include <QPushButton>
#include "../DataBase/Location/filereader.h"
#include "../DataBase/searchengine.h"
#include <QStringList>
#include <QCompleter>

namespace Ui {
class Other;
}

class Other : public QDialog
{
    Q_OBJECT

public:
    explicit Other(QWidget *parent = nullptr, FileReader* = nullptr, SearchEngine* searchEngine = nullptr);
    ~Other();
    FileReader* fileReader;
    SearchEngine* searchEngine;

private slots:
    void otherReceiveshow();

    void on_toolButton_home_clicked();

    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();
    void on_comboBox_Language_currentIndexChanged(int index);

    void on_comboBoxStates_activated(const QString &arg1);

signals:
    void otherShowmainwindow();
    void translateToSpanish();
    void translateToEnglish();


private:
    Ui::Other *ui;
};

#endif // OTHER_H
