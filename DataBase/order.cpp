#include "order.h"

int Order::lastID = 0;

/**
* @brief Order constructor
* @param adopter ID, animal ID
*/

Order::Order(int adptrID,int anmlID,string status)
{
    ID = Order::lastID + 1;
    Order::lastID++;
    adopterID = adptrID;
    animalID = anmlID;
    status = "unfinished";
}

/**
* @brief Order constructor for order
* @param order ID, adopter ID, animal ID,created date, shipped date, status
*/
Order::Order(int id, int adptrID, int anmlID, string istatus,int likeNum){
    ID = id;
    adopterID = adptrID;
    animalID = anmlID;
    status = istatus;
    this->likeNum = likeNum;
}

/**
* @brief get order ID
*/
int Order::getID(){
    return this->ID;
}

/**
* @brief get adopter ID
*/
int Order::getAdopterID(){
    return this->adopterID;
}

/**
* @brief get animal ID
*/
int Order::getAnimalID(){
    return this->animalID;
}


/**
* @brief get the order status
*/
string Order::getStatus(){
    return this->status;
}

void Order::print()
{
    cout << this->getID() << " | " << this->getAdopterID() << " | " << this->getAnimalID() << endl;

}

//TODO
int Order::getLikeNum(){
    return this->likeNum;
}
