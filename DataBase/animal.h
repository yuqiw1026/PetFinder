#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <QtSql>
#include <iostream>
#include <vector>

using namespace std;

class Animal
{
private:
    static int lastID;
    int ID;
    int shelterID;
    string name;
    string gender;

    string fileName;
   // QByteArray inByteArray;
public:
    string species;
    string breed;
    string age;
    string size;
    string color;
    string coatLength;
    string energyLevel;
    /**
 * @brief Animal constructor
 * @param
 */
    Animal(int id, int shelterID, string species, string breed, string name, string gender,
           string age, string size, string color, string coatLength, string energyLevel,string fileName);

    /**
 * @brief get animal ID
 */
    int getID();

    /**
 * @brief input shelter ID
 * @param shelter ID
 */
    void setShelterID(int newShelterID);

    /**
 * @brief get shelter ID
 */
    int getShelterID();

    /**
 * @brief input animal name
 * @param animal name
 */
    void setName(string newName);

    /**
 * @brief get animal name
 */
    string getName();

    /**
 * @brief get gender of the animal
 */
    string getGender();

    string getFileName();
    /**
 * @brief print info of an animal
 */
    void print();
    string getInformation();
    QString getPicLocation();
};

#endif // ANIMAL_H
