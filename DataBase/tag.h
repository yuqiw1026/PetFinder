#ifndef TAG_H
#define TAG_H

#include <string>
#include <iostream>
#include <QtSql>

using namespace std;

class Tag
{
private:
    //static int lastID;
    int ID;
    string tagName;
    string tagContent;

public:
    Tag();
    Tag( int ID,string tgName,string tgContent);
    Tag(string tagName,string tgContent);
    int getID();
    string getTagContent();
    string getTagName();
    void print();

};

#endif // TAG_H
