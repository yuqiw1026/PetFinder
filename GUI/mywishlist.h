#ifndef MYWISHLIST_H
#define MYWISHLIST_H

#include <QWidget>

namespace Ui {
class mywishlist;
}

class mywishlist : public QWidget
{
    Q_OBJECT

public:
    explicit mywishlist(QWidget *parent = 0);
    ~mywishlist();

private slots:
    void on_toolButton_home_clicked();

    void wishlistReceivesshow();



signals:
    void wlShowmainwindow();
private:
    Ui::mywishlist *ui;
};

#endif // MYWISHLIST_H
