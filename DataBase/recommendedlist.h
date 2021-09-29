#ifndef RECOMMENDEDLIST_H
#define RECOMMENDEDLIST_H

#include <string>
#include <iostream>
using namespace std;

class RecommendedList
{
private:
    int ID;
    int adopterID;
    int animalID;
public:
    RecommendedList();
    RecommendedList(int ID, int adopterID, int animalID);
    RecommendedList(int adopterID, int animalID);
    int getID();
    int getAdopterID();
    int getAnimalID();
    void print();
};

#endif // RECOMMENDEDLIST_H
