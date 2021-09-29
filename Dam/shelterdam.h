#ifndef SHELTERDAM_H
#define SHELTERDAM_H
#include "../DataBase/shelter.h"
#include <vector>
#include <QtSql>

class ShelterDam
{
private:
    vector<Shelter*> shelters;
    int recordTo;
public:
    ShelterDam();
    void write();
    void read();
    void remove(int shelterID);
    bool add(Shelter* shelter);
    bool hasShelter(Shelter* shelter);
    void printAll();
    bool addNewShelter(string name, string address, string tel, string email);
    string getShelterAddressByID(int id);
};

#endif // SHELTERDAM_H

