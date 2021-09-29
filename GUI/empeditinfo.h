#ifndef EMPEDITINFO_H
#define EMPEDITINFO_H

#include <QWidget>

namespace Ui {
class empeditinfo;
}

class empeditinfo : public QWidget
{
    Q_OBJECT

public:
    explicit empeditinfo(QWidget *parent = 0);
    ~empeditinfo();

private:
    Ui::empeditinfo *ui;
};

#endif // EMPEDITINFO_H
