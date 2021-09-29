#include "recommendedlistdam.h"

RecommendedListDam::RecommendedListDam()
{
    this->recordTo = 0;
}
void RecommendedListDam::write()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RecommendedList (ID, AdopterID, AnimalID) VALUES (:ID, :AdopterID, :AnimalID);");

    for (unsigned int i = 0; i < recommendedLists.size(); i++) {
        RecommendedList* recommendedList = recommendedLists[i];
        // Only insert new adopters
        if (recommendedList->getID() > recordTo) {
            query.bindValue(":ID", recommendedList->getID());
            query.bindValue(":AdopterID", recommendedList->getAdopterID());
            query.bindValue(":AnimalID", recommendedList->getAnimalID());
            recordTo++;
            if (!query.exec()) {
                qDebug() << query.lastError();
            }
        }
    }
}
void RecommendedListDam::read()
{
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select * from RecommendedList;")) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        int id = query.value("ID").toInt();
        int adopterID = query.value("AdopterID").toInt();
        int animalID= query.value("AnimalID").toInt();

        RecommendedList* recommendedList = new RecommendedList(id, adopterID, animalID);
        recommendedLists.push_back(recommendedList);
        // Update the existing ID threshold
        if (id > recordTo) {
            recordTo = id;
        }
    }
}


void RecommendedListDam::add(RecommendedList* recommendedList)
{
    if(!hasRecoomendedList(recommendedList)){
        recommendedLists.push_back(recommendedList);
    }
}

bool RecommendedListDam::hasRecoomendedList(RecommendedList* recommendedList)
{
    for (unsigned int i = 0; i < recommendedLists.size(); i++)
    {
        if(recommendedLists[i]->getID() == recommendedList->getID()){
            return true;
        }
    }
    return false;
}
void RecommendedListDam::printAll()
{
    for (unsigned int i = 0; i < recommendedLists.size(); i++)
    {
        recommendedLists[i]->print();
    }
}

/**
  *search for all all the recommendedlist with the same adopterID
  *and then return the vector of those animal IDs
 */
vector<int>* RecommendedListDam::getAllRecommended(int adopterID)
{
    vector<int> *animalIDs = new std::vector<int>;;
    for (unsigned int i = 0; i < recommendedLists.size(); i++)
    {
        if(recommendedLists[i]->getAdopterID() == adopterID)
        {
           animalIDs->push_back(recommendedLists[i]->getAnimalID());
        }
    }
    return animalIDs;
}
