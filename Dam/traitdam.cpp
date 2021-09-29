#include "traitdam.h"

TraitDam::TraitDam()
{
    this->recordTo = 0;
    this->read();
}

void TraitDam::read()
{
    int countNum = 0;
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select * from Trait;")) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        int tagID = query.value("TagID").toInt();
        int animalID = query.value("AnimalID").toInt();
        Trait* trait = new Trait(tagID, animalID);
        traits.push_back(trait);
        countNum++;
        cout << "??" << endl;
    }
     //Update the existing ID threshold if recordTo somehow didn't keep up
    if(countNum > (int)recordTo){
        recordTo = countNum;
    }
}

bool TraitDam::add(Trait* trait)
{
    if(!hasTrait(trait)){
        traits.push_back(trait);
        cout << "Adding" << endl;
        return true;
    }
    return false;
}

bool TraitDam::hasTrait(Trait *trait)
{
    for (unsigned int i = 0; i < traits.size(); i++)
    {
       //cout << traits[i]->getTagID() << " | " << trait->getTagID() << endl;
       //cout << traits[i]->getAnimalID() << " | " << trait->getAnimalID() << endl;
        if(traits[i]->getTagID() == trait->getTagID() ){
            if(traits[i]->getAnimalID() == trait->getAnimalID()){
                cout << "what" << endl;
                return true;
            }
        }
    }
    return false;
}

void TraitDam::printAll()
{
    for (unsigned int i = 0; i < traits.size(); i++)
    {
        traits[i]->print();
    }

}
void TraitDam::write()
{
    QSqlQuery query;

    for (unsigned int i = 0; i < traits.size(); i++) {
        Trait* trait = traits[i];
        // Only insert new tag-animal labels
        if(recordTo < i + 1){
            query.prepare("INSERT INTO Trait (TagID, AnimalID) VALUES (:TagID, :AnimalID);");
            query.bindValue(":TagID", trait->getTagID());
            query.bindValue(":AnimalID", trait->getAnimalID());
            if (!query.exec()) {
                qDebug() << query.lastError();
            }
            recordTo++;
        }
    }
}
bool TraitDam::addNewTrait(int tagID, int animalID)
{
    cout << "recordTo: " << recordTo << endl;
    Trait* trait = new Trait(tagID, animalID);
    cout << "success "  << endl;
    if(this->add(trait)){
        this->write();
        return true;
    }
    return false;

}

void TraitDam::removeAnimal(int animalID){
    for (unsigned int i = 0; i < traits.size(); i++)
    {
        if(traits[i]->getAnimalID() == animalID){
            traits.erase(traits.begin() + i);
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Trait WHERE AnimalID ==?");
    query.addBindValue(animalID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

void TraitDam::removeTag(int tagID){
    for (unsigned int i = 0; i < traits.size(); i++)
    {
        if(traits[i]->getTagID() == tagID){
            traits.erase(traits.begin() + i);
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Trait WHERE TagID ==?");
    query.addBindValue(tagID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

vector<int>* TraitDam::getAllFromOneTagID(int tagID)
{
    vector<int>* ids = new vector<int>();
    for(unsigned int i = 0; i < traits.size(); i++){
        if(traits[i]->getTagID() == tagID){
            ids->push_back(traits[i]->getAnimalID());
        }
    }
    return ids;
}

