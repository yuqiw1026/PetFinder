#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#include "user.h"

using namespace std;

class Employee:public User
{
private:
    int ID;
    int shelterID;
public:

    Employee(int id, string passWord, string userName, string gender,
    int age, int shelterID, string phoneNumber, string email);
    Employee(string passWord, string userName, string gender,
    int age, string phoneNumber, string email);

    ~Employee();
    int getID();
    void setShelterID(int shelterID);
    int getShelterID();
    void print();
};

#endif // EMPLOYEE_H
