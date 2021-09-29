#include "animal.h"

int Animal::lastID = 0;

/**
* @brief Animal constructor
* @param name of the shelter that the animal is from,animal name and gender of the animal
*/
//Animal::Animal(int id, int ashelterID, string aname, string agender, string fileName )
//{
//    this->ID = id;
//    shelterID = ashelterID;
//    name = aname;
//    gender = agender;
//    this->fileName = fileName;
//}

Animal::Animal(int id, int shelterID, string species, string breed, string name, string gender,
                   string age, string size, string color, string coatLength, string energyLevel,string fileName)
{
    this->ID = id;
    this->shelterID = shelterID;
    this->species = species;
    this->breed = breed;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->size = size;
    this->color = color;
    this->coatLength = coatLength;
    this->energyLevel = energyLevel;
    this->fileName = fileName;
}

/**
* @brief get animal ID
*/
int Animal::getID(){
    return ID;
}

/**
* @brief input shelter ID
* @param shelter ID
*/
void Animal::setShelterID(int newShelterID){
    shelterID = newShelterID;
}

/**
* @brief get shelter ID
*/
int Animal::getShelterID(){
    return shelterID;
}

/**
* @brief input animal name
* @param animal name
*/
void Animal::setName(string newName){
    name = newName;
}

/**
* @brief get animal name
*/
string Animal::getName(){
    return name;
}

/**
* @brief get gender of the animal
*/
string Animal::getGender(){
    return gender;
}

/**
* @brief print information of an animal, its id number, shelter id, name and gender.
*/
void Animal::print()
{
    cout << this->getID() << " | " << this->getShelterID() << " | " << this-> getName() << " | " << this-> getGender() << endl;

}

string Animal::getFileName()
{
    return this->fileName;
}

QString Animal::getPicLocation()
{
    QString::fromStdString("" + this->fileName);
    QString picLocation = QString::fromStdString("../../../../DataBase/Pictures/" + this->fileName);

    return picLocation;
}
string Animal::getInformation()
{
    string s = to_string(ID) + " | " + to_string(shelterID) + " | " + name + " | " + species + " | " + breed +" | " + age +" | " + size +
            " | " + color + " | " + coatLength + " | " + energyLevel + " | " + fileName ;
    return s;
}
