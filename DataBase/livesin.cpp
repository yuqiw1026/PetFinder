#include "livesin.h"

int LivesIn::lastId = 0;
vector<LivesIn*> liveIns;

LivesIn::LivesIn(int shltrId, int nmlId)
{
    shelterID = shltrId;
    animalID = nmlId;
}


int LivesIn::getShelterID(){
    return shelterID;
}

int LivesIn::getAnimalID(){
    return animalID;
}


/**
* @brief print the id of the animal and the id of the shelter it lives in
*/
void LivesIn::print()
{
    cout << this->getAnimalID() << " | " << this->getShelterID() << endl;
}
