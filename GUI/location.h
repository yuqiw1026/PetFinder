#ifndef LOCATION_H
#define LOCATION_H

#include <QDialog>

namespace Ui {
class Location;
}

class Location : public QDialog
{
    Q_OBJECT

public:
    explicit Location(QWidget *parent = nullptr);
    ~Location();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Location *ui;
};

#endif // LOCATION_H
