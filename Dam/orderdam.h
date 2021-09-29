#ifndef ORDERDAM_H
#define ORDERDAM_H
#include <string>
#include <QtSql>
#include <vector>
#include <string>
#include "../DataBase/order.h"

using namespace std;

class OrderDam
{
private:
    int recordTo;
public:
    OrderDam();
    vector<Order*> orders;

    void read();
    bool add(Order* order);
    bool hasOrder(Order* order);
    void printAll();
    bool addNewOrder(int adopterID, int animalID, string status, int likeNum);
    void approveOrder(Order* order);
    void rejectOrder(Order* order);
    vector<Order*>* getOrdersForOneAdopter(int adopterID);
    vector<Order*>* getAllWaitingOrders();
    void deleteOneOrder(Order* order);
    void insertOneOrder(Order* order);
    void completeOrder(Order* order);
};

#endif // ORDERDAM_H
