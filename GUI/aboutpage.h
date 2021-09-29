#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>

namespace Ui {
class aboutpage;
}

class aboutpage : public QWidget
{
    Q_OBJECT

public:
    explicit aboutpage(QWidget *parent = 0);
    ~aboutpage();

private slots:
    void on_pushButtonPetFinder_4_clicked();

    void aboutReceiveshow();


signals:
    void aboutShowmainwindow();

private:
    Ui::aboutpage *ui;
};

#endif // ABOUTPAGE_H
