#ifndef ADOPTERDAM_H
#define ADOPTERDAM_H
#include <string>
#include <QtSql>
#include <vector>
#include <sstream>
#include "../DataBase/UserInfo/adopter.h"

using namespace std;

class AdopterDam
{
private:
    unsigned int recordTo;
public:
    AdopterDam();
    void read();
    int add(Adopter* adopter);
    bool addNewAdopter(string passWord, string userName, string gender,
                       int age, string phoneNumber, string email,
                       string livingCondition, string address);
    bool hasAdopter(Adopter* adopter);
    void printAll();
    int loggin(string userName, string passWord);
    Adopter* getAdopterByName(string name);
    int getSize();
   // void updateIndividual(Adopter* adopter);
    int updateIndividual(Adopter* oldAdopter, string newUserName,
                          string newGender, int newAge,
                          string newPhoneNo, string newEmail,
                          string currentPasswd, string newPasswd,
                          string newPasswd2, string newCity, string newState);
    void insertOneAdopter(Adopter* adopter);
    string getAdopterNameByID(int adotperID);
};

#endif // ADOPTERDAM_H
