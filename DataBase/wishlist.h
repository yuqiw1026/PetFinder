#ifndef WISHLIST_H
#define WISHLIST_H

#include <string>
#include <iostream>

using namespace std;

class WishList
{
public:
    int ID;
    int adoptorID;
    string preferred_energyLevel;
    string preferred_coatLength;
    string preferred_color;
    string preferred_size;
private:

public:
    WishList(int id, int adoptorID, string energyLevel, string coatLength, string color, string size);
    int getID();
    int getAdoptorID();
    int getAnimalID();
    void printAll();
    void print();
};

#endif // WISHLIST_H
