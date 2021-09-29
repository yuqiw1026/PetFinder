#include "user.h"

User::User()
{
    passWord = "";
    userName = "";
    gender = "";
    age = 0;
    phoneNumber = "";
    email = "";
}

User::User(std::string passWord, std::string userName, std::string gender,
int age, std::string phoneNumber, std::string email)
{
    this->passWord = passWord;
    this->userName = userName;
    this->gender = gender;
    this->age = age;
    this->phoneNumber = phoneNumber;
    this->email = email;
}
string User::getPassWord()
{
    return this->passWord;
}
string User::getUserName()
{
    return this->userName;
}
int User::getAge()
{
    return this->age;
}
string User::getGender()
{
    return this->gender;
}

string User::getPhoneNo()
{
    return this->phoneNumber;
}

string User::getEmail()
{
    return this->email;
}
void User::setPhoneNo(string phoneNo)
{
    this->phoneNumber = phoneNo;
}
