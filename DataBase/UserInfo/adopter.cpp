#include "adopter.h"

Adopter::Adopter()
{

}
/*
Adopter::Adopter(string passWord, string userName, string gender,
int age, string phoneNumber, string email, string livingCondition,
string address):User(passWord, userName, gender, age, phoneNumber, email)
{
    this->ID = ++lastId;
    this->livingCondition = livingCondition;
    this->address = address;
}
*/

Adopter::Adopter(int id, string passWord, string userName, string gender,
int age, string phoneNumber, string email, string livingCondition,
string address):User(passWord, userName, gender, age, phoneNumber, email)
{
    this->ID = id;
    this->livingCondition = livingCondition;
    this->address = address;
}

void Adopter::print()
{
    cout << this->getID()<< " | " << this->getUserName() << endl;

}
int Adopter::getID()
{
    return this->ID;
}
string Adopter::getLivingCondition()
{
    return this->livingCondition;
}
string Adopter::getAddress()
{
    return this->address;
}

