#ifndef QUESTIONAIRE_H
#define QUESTIONAIRE_H
#include "display.h"
#include <QDialog>

namespace Ui {
class questionaire;
}

class questionaire : public QDialog
{
    Q_OBJECT

public:
    explicit questionaire(QWidget *parent = 0);
    ~questionaire();
    display *dpage;

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::questionaire *ui;
};

#endif // QUESTIONAIRE_H
