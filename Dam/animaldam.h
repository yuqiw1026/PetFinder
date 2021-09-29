#ifndef ANIMALDAM_H
#define ANIMALDAM_H
#include <string>
#include <QtSql>
#include <vector>
#include "../DataBase/animal.h"
#include <QLabel>
using namespace std;

class AnimalDam
{
private:
    unsigned int recordTo;

public:
    AnimalDam();
    vector<Animal*> animals;

    void read();
    void remove(int animalID);
    bool add(Animal* animal);
    bool hasAnimal(Animal* animal);
    bool hasAnimal(int id);
    void printAll();
    bool addNewAnimal(int shelterID, string species, string breed, string name, string gender,
                      string age, string size, string color, string coatLength, string energyLevel,string fileName);
    vector<QString>* getAllPicLocation();
    bool hasFileName(Animal* animal);
    vector<Animal*>* getAnimalsByIDs(vector<int>* ids);
    vector<Animal*>* getAnimalsfromOneSpecies(string species);

    vector<Animal*>* searchForOneInOneSpecies(string speciesName, string traitName, string context);
    QSqlQuery* getAllAnimalsInfo();
    int getShelterIDByAnimalID(int animalID);
    bool insertOneAnimal(Animal* animal);
};
#endif // ANIMALDAM_H
