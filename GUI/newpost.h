#ifndef NEWPOST_H
#define NEWPOST_H

#include <QWidget>
#include <string>
#include "../DataBase/searchengine.h"
namespace Ui {
class NewPost;
}

class NewPost : public QWidget
{
    Q_OBJECT

public:
    explicit NewPost(QWidget *parent = nullptr);
    ~NewPost();
    int adopterID;
    SearchEngine* mySearchEngine;

private slots:
    void receivesTranslateToSpanish();
    void receivesTranslateToEnglish();
    void on_pushButton_post_clicked();

private:
    Ui::NewPost *ui;
};

#endif // NEWPOST_H
