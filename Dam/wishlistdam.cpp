#include "wishlistdam.h"

WishListDam::WishListDam()
{
    this->recordTo = 0;
    this->read();
}
void WishListDam::write()
{
    QSqlQuery query;
    query.prepare("INSERT INTO WishList (ID, AdopterID, AnimalID) VALUES (:ID, :AdopterID, :AnimalID);");

    for (unsigned int i = 0; i < wishLists.size(); i++) {
        WishList* wishList = wishLists[i];
        // Only insert new adopters
        if (wishList->getID() > recordTo) {
            query.bindValue(":ID", wishList->getID());
            query.bindValue(":AdopterID", wishList->getAdoptorID());
            recordTo++;
            if (!query.exec()) {
                qDebug() << query.lastError();
            }
        }
    }
}

void WishListDam::read()
{
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select ID from WishList;")) {
        qDebug() << query.lastError();
    }

    while (query.next()) {
        int id = query.value("ID").toInt();
       // int adopterID = query.value("AdopterID").toInt();
        //int animalID = query.value("AnimalID").toInt();

       // WishList* wishList = new WishList(id, adopterID, animalID);

        //wishLists.push_back(wishList);
        // Update the existing ID threshold
        if (id > recordTo) {
            recordTo = id;
        }
    }
}

void WishListDam::add(WishList *wishList)
{
    if(!hasWishList(wishList)){
        wishLists.push_back(wishList);
    }
}

bool WishListDam::hasWishList(WishList *wishList)
{
//    for (unsigned int i = 0; i < wishLists.size(); i++)
//    {
//        if(wishLists[i]->getID() == wishList->getID() ||){
//            return true;
//        }
//    }
    string temp = "select * from WishList where ID =" + to_string(wishList->getID()) +" or AdopterID = "+ to_string(wishList->getAdoptorID()) +";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
            cout << "it has this wishList already" << endl;
            return true;
        }
        cout << "it does not have this wishList" << endl;

    return false;
}
bool WishListDam::hasWishList(int adopterID)
{

    string temp = "select * from WishList where AdopterID =" + to_string(adopterID) +";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
            //cout << "it has this wishList already" << endl;
            return true;
        }
       // cout << "it does not have this wishList" << endl;

    return false;
}
void WishListDam::printAll()
{
    for (unsigned int i = 0; i < wishLists.size(); i++)
    {
        wishLists[i]->print();
    }
}

WishList* WishListDam::getWishListByAdopterID(int adopterID)
{
    QSqlQuery query;
    // Check for errors
    string s = "select * from WishList where AdopterID = " + to_string(adopterID) + ";";
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }

    if (query.next()) {
        int id = query.value("ID").toInt();
        int adopterID = query.value("AdopterID").toInt();
        string energyLevel = query.value("EnergyLevel").toString().toStdString();
        string coatLength =  query.value("CoatLength").toString().toStdString();
        string color =  query.value("Color").toString().toStdString();
        string size = query.value("Size").toString().toStdString();
        WishList* wishList = new WishList(id, adopterID, energyLevel,coatLength,color, size);
        return wishList;
    }
    return nullptr;
}

bool WishListDam::addNewWishList(int adopterID, string energyLevel, string coatLength, string color, string size)
{
    WishList* wishList = new WishList(recordTo + 1, adopterID, energyLevel, coatLength, color, size);
    if(!hasWishList(wishList)){
        insertOneWishList(wishList);
        return true;
    }
    return false;
}

void WishListDam::insertOneWishList(WishList *wishList)
{
    QSqlQuery query;
    query.prepare("INSERT INTO WishList (ID, AdopterID, EnergyLevel, CoatLength, Color, Size ) VALUES (:ID, :AdopterID, :EnergyLevel, :CoatLength, :Color, :Size );");

        // Only insert new adopters
            query.bindValue(":ID", wishList->getID());
            query.bindValue(":AdopterID", wishList->getAdoptorID());
            query.bindValue(":EnergyLevel", QString::fromStdString(wishList->preferred_energyLevel));
            query.bindValue(":CoatLength", QString::fromStdString(wishList->preferred_coatLength));
            query.bindValue(":Color", QString::fromStdString(wishList->preferred_color));
            query.bindValue(":Size", QString::fromStdString(wishList->preferred_size));

            if (!query.exec()) {
                qDebug() << query.lastError();
            }else{
                recordTo++;
            }

}
vector<string>* WishListDam::getPreferencesByAdopterID(int id)
{
    vector<string>* temp = new vector<string>();
    QSqlQuery query;
    // Check for errors
    string s = "select * from WishList where AdopterID = " + to_string(id) + ";";
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }

    if (query.next()) {
        string energyLevel = query.value("EnergyLevel").toString().toStdString();
        string coatLength =  query.value("CoatLength").toString().toStdString();
        string color = query.value("Color").toString().toStdString();
        string size = query.value("Size").toString().toStdString();
        temp->push_back(energyLevel);
        temp->push_back(coatLength);
        temp->push_back(color);
        temp->push_back(size);
    }
    return temp;
}
