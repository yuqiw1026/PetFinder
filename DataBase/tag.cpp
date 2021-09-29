#include "tag.h"


//int static lastid = 0;
Tag::Tag()
{
\
}

Tag::Tag(int ID, string tagName, string tgContent)
{
    this->tagName = tagName;
    this->ID = ID;
    this->tagContent = tgContent;
}

Tag::Tag(string tagName, string tgContent)
{
    this->tagName = tagName;
   // this->ID = ++lastid;
    this->tagContent = tgContent;
}

string Tag::getTagName()
{
    return this-> tagName;
}

int Tag::getID()
{
    return this-> ID;
}

string Tag::getTagContent()
{
    return this-> tagContent;
}

void Tag::print()
{
       cout << this->getID()<< " | " << this->getTagName() << endl;
}

