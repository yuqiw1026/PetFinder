#include "animaldam.h"


AnimalDam::AnimalDam()
{
    this->recordTo = 0;
    this->read();
}

/**
* @brief get animal information from the database and store it in animal class,
* then put it into the vector "animals"
*/
void AnimalDam::read()
{
    QSqlQuery query;

    // Check for errors
    if (!query.exec("select ID from Animal;")) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        int id = query.value("ID").toInt();
        if (id > recordTo) {
            recordTo = id;
        }
    }
}

void AnimalDam::remove(int animalID){
    for (unsigned int i = 0; i < animals.size(); i++)
    {
        if(animals[i]->getID() == animalID){
            animals.erase(animals.begin() + i);
            break;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Animal WHERE Animal.ID ==?");
    query.addBindValue(animalID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

bool AnimalDam::add(Animal* animal)
{
    if(!hasAnimal(animal)){
        animals.push_back(animal);
        return true;
    }
    return false;
}

bool AnimalDam::hasAnimal(Animal *animal)
{
    string temp = "select * from Animal where ID = " + to_string(animal->getID()) + ";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
          //  cout << "it has this Animal already" << endl;
            return true;
        }
        // cout << "it does not have this Animal" << endl;
    return false;
}
bool AnimalDam::hasAnimal(int id)
{
    string temp = "select * from Animal where ID = " + to_string(id) + ";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
          //  cout << "it has this Animal already" << endl;
            return true;
        }
        // cout << "it does not have this Animal" << endl;
    return false;
}

bool AnimalDam::hasFileName(Animal *animal)
{
    for (unsigned int i = 0; i < animals.size(); i++)
    {
        if(animals[i]->getFileName() == animal->getFileName()){
            return true;
        }
    }
    return false;
}
/**
* @brief print all animals from the vector collecting all animal information
*/
void AnimalDam::printAll(){
    for (unsigned int i = 0; i < animals.size(); i++)
    {
        animals[i]->print();
    }
}
bool AnimalDam::addNewAnimal(int shelterID, string species, string breed, string name, string gender,
                             string age, string size, string color, string coatLength, string energyLevel,string fileName)
{
    //cout << "Animal RecordTo: " << recordTo << endl;
    Animal* animal = new Animal(recordTo+1, shelterID, species, breed, name,gender,
                                age, size, color, coatLength, energyLevel, fileName);
    if(!this->hasAnimal(animal)){
       insertOneAnimal(animal);
        return true;
    }
    return false;
}

vector<QString>* AnimalDam::getAllPicLocation()
{
    vector<QString>* picLocations = new vector<QString>();
    QSqlQuery query;

    // Check for errors
    if (!query.exec("select FileName from Animal;")) {
        qDebug() << query.lastError();
    }

    while (query.next()) {
        // Read the attributes of the next animal record
        string fileName = query.value("FileName").toString().toStdString();
        QString::fromStdString("" + fileName);
        QString picLocation = QString::fromStdString("../../../../DataBase/Pictures/" + fileName);
        picLocations->push_back(picLocation);
    }
    return picLocations;
}

vector<Animal*>* AnimalDam::getAnimalsByIDs(vector<int>* ids)
{
        vector<Animal*>* temp = new vector<Animal*>();
        for(unsigned int i = 0; i < ids->size(); i++){
            string s = "select * from Animal where ID = " + to_string((*ids)[i]) + " ;";
            QSqlQuery query;
            // Check for errors
            if (!query.exec(QString::fromStdString(s))) {
                qDebug() << query.lastError();
            }
            if (query.next()) {
                // Read the attributes of the next animal record
                int id = query.value("ID").toInt();
                int shelterID = query.value("ShelterID").toInt();
                string species = query.value("Species").toString().toStdString();
                string breed = query.value("Breed").toString().toStdString();
                string name = query.value("Name").toString().toStdString();
                string gender = query.value("Gender").toString().toStdString();
                string age = query.value("Age").toString().toStdString();
                string size = query.value("Size").toString().toStdString();
                string color = query.value("Color").toString().toStdString();
                string coatLength = query.value("CoatLength").toString().toStdString();
                string energyLevel = query.value("EnergyLevel").toString().toStdString();
                string fileName = query.value("FileName").toString().toStdString();

                Animal* animal = new Animal(id, shelterID, species, breed, name,gender,
                                            age, size, color, coatLength, energyLevel, fileName);
                temp->push_back(animal);
            }
        }
        return temp;
}
vector<Animal*>* AnimalDam::getAnimalsfromOneSpecies(string species)
{
    vector<Animal*>* temp = new vector<Animal*>();
        string s = "select * from Animal where Species = \"" + species + "\" ;";
        QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(s))) {
            qDebug() << query.lastError();
        }
        while (query.next()) {
            // Read the attributes of the next animal record
            int id = query.value("ID").toInt();
            int shelterID = query.value("ShelterID").toInt();
            string species = query.value("Species").toString().toStdString();
            string breed = query.value("Breed").toString().toStdString();
            string name = query.value("Name").toString().toStdString();
            string gender = query.value("Gender").toString().toStdString();
            string age = query.value("Age").toString().toStdString();
            string size = query.value("Size").toString().toStdString();
            string color = query.value("Color").toString().toStdString();
            string coatLength = query.value("CoatLength").toString().toStdString();
            string energyLevel = query.value("EnergyLevel").toString().toStdString();
            string fileName = query.value("FileName").toString().toStdString();

            Animal* animal = new Animal(id, shelterID, species, breed, name,gender,
                                        age, size, color, coatLength, energyLevel, fileName);
            temp->push_back(animal);
        }
    return temp;
}

vector<Animal*>* AnimalDam::searchForOneInOneSpecies(string speciesName,string traitName,string context){

    vector<int>* temp = new vector<int>();
    string s = "select * from Animal where Species = \"" + speciesName+ "\" and \"" + traitName +"\" = \"" + context+"\" ;";
    QSqlQuery query;


    // Check for errors
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }
   // cout << query.lastQuery().toStdString() << endl;
    while (query.next()) {
        // Read the attributes of the next animal record
        int id = query.value("ID").toInt();
        (*temp).push_back(id);

    }
    return getAnimalsByIDs(temp);
}

QSqlQuery* AnimalDam::getAllAnimalsInfo()
{
    QSqlQuery* qry = new QSqlQuery();
    QString sql = "select ID, ShelterID, Species, Breed, Name, Gender, Age, Size from Animal;";
    (*qry).exec(sql);
    return qry;
}


int AnimalDam::getShelterIDByAnimalID(int animalID)
{
    string s = "select ShelterID from Animal where ID = " + to_string(animalID) +  ";";
    QSqlQuery query;
    int shelterID = -1;
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }
    //cout << query.lastQuery().toStdString() << endl;
    if (query.next()) {
        // Read the attributes of the next animal record
        shelterID = query.value(0).toInt();
        cout << "shelterID " << shelterID << endl;
    }
    return shelterID;
}
bool AnimalDam::insertOneAnimal(Animal *animal)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Animal (ID, ShelterID, Species, Breed, Name, Gender, Age, Size, Color, CoatLength, EnergyLevel,FileName) "
               "VALUES (:ID, :ShelterID, :Species, :Breed, :Name, :Gender, :Age, :Size, :Color, :CoatLength, :EnergyLevel, :FileName);");
       // Bind values for the animal
           // Only insert new animals
               query.bindValue(":ID", animal->getID());
               query.bindValue(":ShelterID", animal->getShelterID());
               query.bindValue(":Species", QString::fromStdString(animal->species));
               query.bindValue(":Breed", QString::fromStdString(animal->breed));
               query.bindValue(":Name", QString::fromStdString(animal->getName()));
               query.bindValue(":Gender", QString::fromStdString(animal->getGender()));
               query.bindValue(":Age", QString::fromStdString(animal->age));
               query.bindValue(":Size", QString::fromStdString(animal->size));
               query.bindValue(":Color", QString::fromStdString(animal->color));
               query.bindValue(":CoatLength", QString::fromStdString(animal->coatLength));
               query.bindValue(":EnergyLevel", QString::fromStdString(animal->energyLevel));
               query.bindValue(":FileName", QString::fromStdString(animal->getFileName()));
               recordTo = animal->getID();
               if (!query.exec()) {
                   qDebug() << query.lastError();
                   //cout << "Animal insert Problem!" <<endl;
               }



}
