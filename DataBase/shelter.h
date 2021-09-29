#ifndef SHELTER_H
#define SHELTER_H
#include<string>
#include<QtSql>
#include <iostream>

using namespace std;
class Shelter
{
private:
    int ShelterID;
    string ShelterName;
    string ShelterAddress;
    string ShelterTel;
    string ShelterEmail;
public:
    Shelter(int ID, string name, string address, string tel, string email);
    Shelter(string name, string address, string tel, string email);
    ~Shelter();

    int getID();
    string getName();
    string  getAdress();
    string  getTel();
    string  getEmail();
    void print();
    void  setShelterID(int );
    void  setShelterName(string);
    void  setShelterAdress(string );
    void  setShelterTel(string );
    void  setShelterEmail(string );

};

#endif // SHELTER_H
