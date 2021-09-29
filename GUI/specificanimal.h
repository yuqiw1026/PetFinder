#ifndef SPECIFICANIMAL_H
#define SPECIFICANIMAL_H

#include <QWidget>

namespace Ui {
class specificanimal;
}

class specificanimal : public QWidget
{
    Q_OBJECT

public:
    explicit specificanimal(QWidget *parent = 0);
    ~specificanimal();

private:
    Ui::specificanimal *ui;
};

#endif // SPECIFICANIMAL_H
