#ifndef TRAIT_H
#define TRAIT_H
#include <string>
#include <iostream>
#include <QtSql>

using namespace std;

class Trait
{
private:
    int tagID;
    int animalID;

public:
    Trait(int tagID,int nmlID);
    void setAnimalID(int nmlID);
    void setTagID(int tgID);
    int getTagID();
    int getAnimalID();
    void print();
};


#endif // TRAIT_H
