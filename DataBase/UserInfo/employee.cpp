#include "employee.h"
#include <string>



Employee::Employee(string passWord, string userName, string gender,
int age, string phoneNumber, string email):User(passWord, userName, gender, age, phoneNumber, email)
{
}

Employee::Employee(int id, string passWord, string userName, string gender,
int age, int shelterID, string phoneNumber, string email):User(passWord, userName, gender, age, phoneNumber, email)
{
    this->ID = id;
    this->shelterID = shelterID;
}

Employee::~Employee() {

//delete this->ID;
}

int Employee::getID(){
    return this->ID;
}

void Employee::setShelterID(int shelterID){
    this->shelterID = shelterID;
}

int Employee::getShelterID(){
    return this->shelterID;
}

//void Employee::setEmployeePW(string pw){
//  this->passWord = pw;
//}

//void Employee::setEmployeeName(string n){
//   this->name = n;
//}

void Employee::print()
{
    cout << this->getID() << " " << this->getUserName() << endl;
}
