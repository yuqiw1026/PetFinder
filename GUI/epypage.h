#ifndef EPYPAGE_H
#define EPYPAGE_H

#include <QWidget>

namespace Ui {
class epypage;
}

class epypage : public QWidget
{
    Q_OBJECT

public:
    explicit epypage(QWidget *parent = 0);
    ~epypage();

private:
    Ui::epypage *ui;
};

#endif // EPYPAGE_H
