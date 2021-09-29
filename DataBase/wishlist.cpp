#include "wishlist.h"


WishList::WishList(int id, int adoptorID, string energyLevel, string coatLength, string color, string size)
{
    this->ID = id;
    this->adoptorID = adoptorID;
    this->preferred_energyLevel = energyLevel;
    this->preferred_coatLength = coatLength;
    this->preferred_color = color;
    this->preferred_size = size;
}


int WishList::getID()
{
    return this->ID;
}

int WishList::getAdoptorID()
{
    return this->adoptorID;
}

void WishList::print()
{
    cout << this->getID()<< " | " << this->getAdoptorID() <<  endl;
}
