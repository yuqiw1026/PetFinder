#ifndef LIVESIN_H
#define LIVESIN_H

#include <string>
#include <QtSql>
#include <iostream>
#include <vector>

using namespace std;


class LivesIn
{
private:
    static int lastId;
    int shelterID;
    int animalID;
public:
    LivesIn(int shltrId, int nmlId);
    int getShelterID();
    int getAnimalID();
    void print();
};
#endif // LIVESIN_H
