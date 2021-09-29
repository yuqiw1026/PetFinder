#include "shelter.h"


Shelter::Shelter(int ID, string name, string address, string tel, string email)
{
    this->ShelterID   = ID;
    this->ShelterName = name;
    this->ShelterAddress= address;
    this->ShelterTel = tel;
    this->ShelterEmail= email;
}

Shelter::Shelter(string name, string address, string tel, string email)
{
    this->ShelterName = name;
    this->ShelterAddress= address;
    this->ShelterTel = tel;
    this->ShelterEmail= email;
}

Shelter::~Shelter() {

//delete this->ShelterID;
}

int Shelter::getID(){
    return this->ShelterID;
}
string Shelter::getName(){
    return this->ShelterName;
}
string Shelter::getAdress(){
    return this->ShelterAddress;
}
string Shelter::getTel(){
    return this->ShelterTel;
}
string Shelter::getEmail(){
    return this->ShelterEmail;
}

void Shelter::setShelterID(int ID){
    this->ShelterID=ID;
}
void Shelter::setShelterName(std::string nm){
    this->ShelterName=nm;
}
void Shelter::setShelterAdress(std::string ad){
    this->ShelterAddress=ad;
}
void Shelter::setShelterTel(std::string t){
    this->ShelterTel=t;
}
void Shelter::setShelterEmail(std::string em){
    this->ShelterEmail=em;
}

void Shelter::print()
{
    cout << this->getID() << " " << this->getName() << endl;;
}
