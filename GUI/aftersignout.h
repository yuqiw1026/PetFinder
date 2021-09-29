#ifndef AFTERSIGNOUT_H
#define AFTERSIGNOUT_H

#include <QWidget>

namespace Ui {
class Aftersignout;
}

class Aftersignout : public QWidget
{
    Q_OBJECT

public:
    explicit Aftersignout(QWidget *parent = nullptr);
    ~Aftersignout();

private:
    Ui::Aftersignout *ui;
};

#endif // AFTERSIGNOUT_H
