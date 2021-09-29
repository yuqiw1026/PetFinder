#ifndef TAGDAM_H
#define TAGDAM_H

#include <string>
#include <QtSql>
#include <vector>
#include "../DataBase/tag.h"

using namespace std;


class TagDam
{
private:
    unsigned int recordTo;
    vector<Tag*> tags;

public:
    TagDam();
    void write();
    void read();
    void remove(int tagID);
    bool add(Tag* tag);
    bool hasTag(Tag* tag);
    void printAll();
    int getSpecificTag(string tagName, string tagContent);
    bool addNewTag(string tagName,string tagContent);
};

#endif // TAGDAM_H
