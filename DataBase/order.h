#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <QCoreApplication>
#include <QtSql>
#include <string>

using namespace std;

class Order
{
private:
    static int lastID;
    int ID;
    int adopterID;
    int animalID;
    string status;
    int likeNum;
public:
    /**
    * @brief Order constructor for new order
    * @param adopter ID, animal ID, status
    */
    Order(int dptrID,int nmlID, string status);


    /**
    * @brief Order constructor for order
    * @param order ID, adopter ID, animal ID,created date, shipped date, status
    */
    Order(int id, int dptrID, int nmlID, string status, int likeNum);

    /**
    * @brief get order ID
    */
    int getID();

    /**
    * @brief get adopter ID
    */
    int getAdopterID();

    /**
    * @brief get animal ID
    */
    int getAnimalID();

    /**
    * @brief set of the order creation date
    * @param date that order is created
    */
    void setCreatedDate(string date);

    /**
    * @brief get the order status
    */
    string getStatus();


    void print();

    int getLikeNum();

};

#endif // ORDER_H
