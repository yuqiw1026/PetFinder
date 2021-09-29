#ifndef ADOPTER_H
#define ADOPTER_H

#include "./UserInfo/user.h"
#include <string>
#include <QtSql>
#include <iostream>
#include <vector>
using namespace  std;
class Adopter : public User
{
private:
    static int lastId;

    int ID;
    std::string phoneNumber;
    std::string livingCondition;
    std::string address;

public:
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


    void write();
    void read();
    void printAll();
    void print();

};



#endif // ADOPTER_H
