#ifndef ADOPTER_H
#define ADOPTER_H

#include "user.h"
#include <string>
#include <QtSql>
#include <iostream>
using namespace  std;

class Adopter : public User
{
private:
    static int lastId;

    int ID;

public:
    string phoneNumber;
    string livingCondition;
    string address;

    Adopter();
    Adopter(string passWord, string userName, string gender,
             int age, string phoneNumber, string email,
             string livingCondition, string address);
    Adopter(int id, string passWord, string userName, string gender,
             int age, string phoneNumber, string email,
             string livingCondition, string address);
    int getID();
    string getLivingCondition();
    string getAddress();
    void print();

};



#endif // ADOPTER_H
