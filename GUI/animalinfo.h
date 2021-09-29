#ifndef ANIMALINFO_H
#define ANIMALINFO_H

#include <QWidget>

namespace Ui {
class AnimalInfo;
}

class AnimalInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalInfo(QWidget *parent = 0);
    ~AnimalInfo();

private:
    Ui::AnimalInfo *ui;
};

#endif // ANIMALINFO_H
