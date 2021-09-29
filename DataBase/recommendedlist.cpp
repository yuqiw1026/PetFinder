#include "recommendedlist.h"
static int lastID = 0;

RecommendedList::RecommendedList()
{

}

RecommendedList::RecommendedList(int ID, int adopterID, int animalID)
{
    this->ID = ID;
    this->adopterID = adopterID;
    this->animalID = animalID;
}

RecommendedList::RecommendedList(int adopterID, int animalID)
{
    this->ID = ++lastID;
    this->adopterID = adopterID;
    this->animalID = animalID;
}

int RecommendedList::getID()
{
    return this->ID;
}

int RecommendedList::getAdopterID()
{
    return this->adopterID;
}
int RecommendedList::getAnimalID()
{
    return this->animalID;
}
void RecommendedList::print()
{
    cout << this->getAdopterID() << " " << this->animalID << endl;
}
