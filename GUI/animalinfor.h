#ifndef ANIMALINFOR_H
#define ANIMALINFOR_H

#include <QWidget>

namespace Ui {
class animalinfor;
}

class animalinfor : public QWidget
{
    Q_OBJECT

public:
    explicit animalinfor(QWidget *parent = 0);
    ~animalinfor();

private:
    Ui::animalinfor *ui;
};

#endif // ANIMALINFOR_H
