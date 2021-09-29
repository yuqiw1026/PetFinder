#include "shelterdam.h"

ShelterDam::ShelterDam()
{
    this->recordTo = 0;
    this->read();
}
void ShelterDam::write(){
    QSqlQuery query;
    query.prepare("INSERT INTO Shelter (ID, Name, Address, Tele, Email) "
                  "values (:ID, :Name, :Address, :Tele, :Email)");

    for(unsigned int i = 0; i < shelters.size(); i++){
        Shelter* shelter = shelters[i];
        if(shelter->getID() > recordTo){
            query.bindValue(":ID", shelter->getID());
            query.bindValue(":Name", QString::fromStdString(shelter->getName()));
            query.bindValue(":Address", QString::fromStdString(shelter->getAdress()));
            query.bindValue(":Tele", QString::fromStdString(shelter->getTel()));
            query.bindValue(":Email", QString::fromStdString(shelter->getEmail()));
            recordTo++;
            if (!query.exec()) {
                qDebug() << query.lastError();

            }
        }
    }
}

void ShelterDam::read()
{
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select * from Shelter;")) {
        qDebug() << query.lastError();
    }

    while (query.next()) {
        int id = query.value("ID").toInt();
        string name = query.value("Name").toString().toStdString();
        string address = query.value("Address").toString().toStdString();
        string tele = query.value("Tele").toString().toStdString();
        string email = query.value("Email").toString().toStdString();

        Shelter* shelter = new Shelter(id, name, address, tele, email);
        shelters.push_back(shelter);
        // Update the existing ID threshold
        if (id > recordTo) {
            recordTo = id;
        }
    }

}

void ShelterDam::remove(int shelterID){
    for (unsigned int i = 0; i < shelters.size(); i++)
    {
        if(shelters[i]->getID() == shelterID){
            shelters.erase(shelters.begin() + i);
            break;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Shelter WHERE Shelter.ID ==?");
    query.addBindValue(shelterID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

bool ShelterDam::add(Shelter* shelter)
{
    if(!hasShelter(shelter)){
        shelters.push_back(shelter);
        return true;
    }
    return false;
}
bool ShelterDam::hasShelter(Shelter* shelter)
{
    for (unsigned int i = 0; i < shelters.size(); i++)
    {
        if(shelters[i]->getID() == shelter->getID()){
            return true;
        }
    }
    return false;
}
void ShelterDam::printAll()
{
    for (unsigned int i = 0; i < shelters.size(); i++)
    {
        shelters[i]->print();
    }
}
bool ShelterDam::addNewShelter(string name, string address, string tel, string email)
{
    cout << "ShelterDam RecordTo: " << recordTo << endl;
    Shelter* shelter = new Shelter(recordTo+1, name, address, tel, email);
    if(this->add(shelter)){
        this->write();
        return true;
    }
    return false;
}

string ShelterDam::getShelterAddressByID(int id)
{
    QSqlQuery query;
    // Check for errors
    string s = "select Address from Shelter where ID = " + to_string(id) + ";";
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }

    if (query.next()) {
        string address = query.value("Address").toString().toStdString();
        return address;
    }
    return "";
}
