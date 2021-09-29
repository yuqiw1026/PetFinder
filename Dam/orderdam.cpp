#include "orderdam.h"


OrderDam::OrderDam()
{
    this->recordTo = 0;
    this->read();
}

/**
* @brief get order information from the database and store it in animal class,
* then put it into the vector "orders"
*/
void OrderDam::read(){
    QSqlQuery query;

    orders.clear();
    // Check for errors
    if (!query.exec("select * from Orders;")) {
        qDebug() << query.lastError();
    }

    while (query.next()) {
        // Read the attributes of the next order record
        int ID = query.value("ID").toInt();

        if (ID > recordTo) {
            recordTo = ID;
        }
    }
}

bool OrderDam::add(Order* order)
{
    if(!hasOrder(order)){
        orders.push_back(order);
        return true;
    }
    return false;
}

bool OrderDam::hasOrder(Order *order)
{
    string temp = "select * from Orders where ID =" + to_string(order->getID()) +" or AnimalID = "+ to_string(order->getAnimalID()) +";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
            cout << "it has this Order already" << endl;
            return true;
        }
        cout << "it does not have this Order" << endl;
    return false;
}

/**
* @brief print all orders from the vector collecting all order information
*/
void OrderDam::printAll(){
    for (unsigned int i = 0; i < orders.size(); i++)
    {
        orders[i]->print();
    }
}
bool OrderDam::addNewOrder(int adopterID, int animalID, string status, int likeNum)
{
    cout << "Order RecordTo: " << recordTo << endl;
    Order* order = new Order(recordTo+1, adopterID, animalID, status, likeNum);
    if(!this->hasOrder(order)){
        this->insertOneOrder(order);
        return true;
    }
    return false;
}

void OrderDam::approveOrder(Order *order)
{

    if(order != nullptr ){
        cout << order->getStatus() <<endl;
        string s = "update Orders set Status = \"Approved\" where ID = " + to_string(order->getID()) + " and Status = \"Waiting For Approval\"" +";";
        QSqlQuery query;

        // Check for errors
        if (!query.exec(QString::fromStdString(s))) {
            qDebug() << query.lastError();
        }
    }
}

void OrderDam::rejectOrder(Order *order)
{
    if(order != nullptr){
        string s = "update Orders set Status = \"Rejected\" where ID = " + to_string(order->getID()) + " and Status = \"Waiting For Approval\"" +";";
        QSqlQuery query;

        // Check for errors
        if (!query.exec(QString::fromStdString(s))) {
            qDebug() << query.lastError();
        }
    }
}
 vector<Order*>* OrderDam::getOrdersForOneAdopter(int adopterID)
 {
     vector<Order*>* temp = new vector<Order*>();
     string s = "select * from Orders where AdopterID = " + to_string(adopterID) + " ;";
     QSqlQuery query;


     // Check for errors
     if (!query.exec(QString::fromStdString(s))) {
         qDebug() << query.lastError();
     }
     while (query.next()) {
         // Read the attributes of the next animal record

         int ID = query.value("ID").toInt();

         int adopterID = query.value("AdopterID").toInt();
         int animalID = query.value("AnimalID").toInt();
         string status = query.value("Status").toString().toStdString();
         int likeNum = query.value("LikeNum").toInt();
         Order* order = new Order(ID, adopterID, animalID, status,likeNum);
         temp->push_back(order);
     }
     return temp;
 }

vector<Order*>* OrderDam::getAllWaitingOrders()
{
    vector<Order*>* temp = new vector<Order*>();
    string s = "select * from Orders where Status = \"Waiting For Approval\" ;";
    QSqlQuery query;

    // Check for errors
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        // Read the attributes of the next animal record

        int ID = query.value("ID").toInt();
        int adopterID = query.value("AdopterID").toInt();
        int animalID = query.value("AnimalID").toInt();
        string status = query.value("Status").toString().toStdString();
        int likeNum = query.value("LikeNum").toInt();
        Order* order = new Order(ID, adopterID, animalID, status,likeNum);
        temp->push_back(order);
    }
    return temp;
}
void OrderDam::deleteOneOrder(Order *order)
{
     string s = "delete from Orders where ID = " + to_string(order->getID()) +" ;";
     QSqlQuery query;

     // Check for errors
     if (!query.exec(QString::fromStdString(s))) {
         qDebug() << query.lastError();
     }
}
void OrderDam::insertOneOrder(Order *order)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Orders (ID, AdopterID, AnimalID, Status, LikeNum) "
               "VALUES (:ID, :AdopterID, :AnimalID, :Status, :LikeNum);");
       // get information for the order
           // Only insert new orders
           if (order -> getID() > recordTo) {
               query.bindValue(":ID", order->getID());
               query.bindValue(":AdopterID", order->getAdopterID());
               query.bindValue(":AnimalID", order->getAnimalID());
               query.bindValue(":Status", QString::fromStdString(order->getStatus()));
               query.bindValue(":LikeNum", order->getLikeNum());
       //update about orders recorded
               if(order->getID() > recordTo){
                   recordTo = order->getID();
               }
               if (!query.exec()) {
                   qDebug() << query.lastError();
                   //cout << "???" << endl;
               }
           }

}
void OrderDam::completeOrder(Order *order)
{
    if(order != nullptr ){
        //cout << order->getStatus() <<endl;
        string s = "update Orders set Status = \"Completed\" where ID = " + to_string(order->getID()) + " and Status = \"Approved\"" +";";
        QSqlQuery query;

        // Check for errors
        if (!query.exec(QString::fromStdString(s))) {
            qDebug() << query.lastError();
        }
    }
}
