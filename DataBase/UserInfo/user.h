#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;
class User
{

private:


public:
    User();
    User(string passWord, string userName, string gender,
         int age, string phoneNumber, string email);
    int getID();
    string getUserName();
    string getPassWord();
    string getGender();
    void setPhoneNo(string phoneNo);
    int getAge();
    string getPhoneNo();
    string getEmail();

    string passWord;
    string userName;
    string gender;
    int age;
    string phoneNumber;
    string email;
};

#endif // USER_H
