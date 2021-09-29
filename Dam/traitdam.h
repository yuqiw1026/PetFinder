#ifndef TRAITDAM_H
#define TRAITDAM_H
#include <string>
#include <QtSql>
#include <vector>
#include "../DataBase/trait.h"

using namespace std;


class TraitDam
{
private:
    unsigned int recordTo;
    vector<Trait*> traits;

public:
    TraitDam();
    void write();
    void read();
    void removeAnimal(int animalID);
    void removeTag(int tagID);
    bool add(Trait* trait);
    bool hasTrait(Trait* trait);
    void printAll();
    bool addNewTrait(int tagID, int animalID);
    vector<int>* getAllFromOneTagID(int tagID);
};


#endif // TRAITDAM_H
