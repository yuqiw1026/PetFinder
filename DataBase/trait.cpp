#include "../DataBase/trait.h"


Trait::Trait(int tgID, int nmlID)
{
    this->tagID = tgID;
    this->animalID = nmlID;
}

void Trait::setAnimalID(int nmlID)
{
    this->animalID = nmlID;
}

void Trait::setTagID(int tgID){
    this->tagID = tgID;
}

int Trait::getTagID()
{
    return this->tagID;
}

int Trait::getAnimalID()
{
    return this->animalID;
}

void Trait::print()
{
    cout << this->getTagID() << " | " << this->getAnimalID() << endl;
}

