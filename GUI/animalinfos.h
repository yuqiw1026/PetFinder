#ifndef ANIMALINFOS_H
#define ANIMALINFOS_H

#include <QWidget>
#include "../Dam/animaldam.h"
#include <string>
#include <QMessageBox>
#include <QStandardItemModel>
namespace Ui {
class AnimalInfos;
}

class AnimalInfos : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalInfos(QWidget *parent = 0, AnimalDam* animalDam = nullptr);
    ~AnimalInfos();
        AnimalDam* myAnimalDam;
        QSqlQuery* qryAnimals;
        int current;
        void updateTable(int currentIndex);

private slots:
    //void on_pushButton_2_clicked();


    void anminfoReceiveshow();
    void on_toolButton_clicked();

    void on_pushButton_addAnimal_clicked();

    void on_deleteanimal_clicked();

    //void on_searchbyid_clicked();

    void on_pushButton_pre_clicked();

    void on_pushButton_next_clicked();

signals:
    void anminfoShowmainwindow();

private:
    Ui::AnimalInfos *ui;
};

#endif // ANIMALINFOS_H
