#include "searchengine.h"

SearchEngine::SearchEngine()
{
    //this->traitDam = new TraitDam();
    this->adopterDam = new AdopterDam();
    this->employeeDam = new EmployeeDam();
    this->animalDam = new AnimalDam();
    this->shelterDam = new ShelterDam();
    this->tagDam = new TagDam;
    this->traitDam = new TraitDam;
    this->orderDam = new OrderDam();
    this->wishListDam = new WishListDam();
    this->postDam = new PostDam();
}
SearchEngine::SearchEngine(AdopterDam* adopterDam, EmployeeDam* employeeDam, AnimalDam* animalDam,
             ShelterDam* shelterDam, TagDam* tagDam, TraitDam* traitDam){
    this->adopterDam = adopterDam;
    this->employeeDam = employeeDam;
    this->animalDam = animalDam;
    this->shelterDam = shelterDam;
    this->tagDam = tagDam;
    this->traitDam = traitDam;
}

AdopterDam* SearchEngine::getAdopterDam()
{
     return this->adopterDam;
}

vector<Animal*>* SearchEngine::getAllFromOneSpecies(string speciesName)
{
    return animalDam->getAnimalsfromOneSpecies(speciesName);
}

vector<Animal*>* SearchEngine::searchForOneInOneSpecies(string species,string traitName, string context){
    return this->animalDam->searchForOneInOneSpecies(species, traitName, context);
}
vector<Animal*>* SearchEngine::getAnimalsByIDs(vector<int>* ids)
{
    return this->animalDam->getAnimalsByIDs(ids);
}
int SearchEngine::getShelterIDByAnimalID(int animalID)
{
    return this->animalDam->getShelterIDByAnimalID(animalID);
}
vector<Order*>* SearchEngine::getAllWaitingOrdersInOneShelter(int shelterID)
{
    vector<Order*>* orders = this->orderDam->getAllWaitingOrders();
    cout << "waiting orders's size " << orders->size() << endl;

    vector<Order*>* results = new vector<Order*>();
    if(orders!= nullptr){
    for(unsigned int i = 0; i < orders->size(); i++){
        if(shelterID == getShelterIDByAnimalID( (*orders)[i]->getAnimalID())){
            results->push_back((*orders)[i]);
        }
    }
    }
    cout << results->size() << endl;
    return results;

}

//bool compare(pair<double, Animal*>& pair1, pair<double, Animal*>& pair2)
//{
//     return pair1.first < pair2.first;
//}

void SearchEngine::insertIntoMap(map<double, Animal*>* temp, double distance, Animal* animal){
    for(auto itr : *temp){
        if(itr.first == distance){
            distance += 0.1;
           return  insertIntoMap(temp, distance, animal);
        }
    }
    temp->insert({distance,animal });
}

map<double, Animal*>* SearchEngine::sortAnimalsOrderByDistance(vector<Animal*>* original, Adopter* adopter)
{
    map<double, Animal*>* temp = new map<double, Animal*>();
    double distance = 0;
    if(this->myfileReader != nullptr){
    for(unsigned int i = 0; i < original->size(); i++){
        distance = getDistanceBetweenAnimalandAdopter((*original)[i], adopter);
        //cout << "distance: " << distance << endl;
        insertIntoMap(temp,distance,(*original)[i] );
    }
    }
    return temp;
}
double SearchEngine::getDistanceBetweenAnimalandAdopter(Animal *animal, Adopter *adopter)
{
    string shelterAddress = this->shelterDam->getShelterAddressByID(animal->getShelterID());
//    cout << "shelterAddress: " << shelterAddress << endl;
//    cout << "shelterID: " << animal->getShelterID() << endl;

    if(shelterAddress != ""){
        return this->myfileReader->distanceEarth(shelterAddress, adopter->getAddress());
    }
    return -1;
}

string SearchEngine::getShelterAddressByID(int shelterID)
{
    return this->shelterDam->getShelterAddressByID(shelterID);
}

vector<string>* SearchEngine::getPreferencesByAdopterID(int adopterID)
{
    return this->wishListDam->getPreferencesByAdopterID(adopterID);

}
bool SearchEngine::addNewWishList(Adopter *adopter, string energyLevel, string coatLength, string color, string size)
{
    return this->wishListDam->addNewWishList(adopter->getID(),energyLevel,coatLength,color,size);
}
bool SearchEngine::adopterhasWishList(Adopter *adopter)
{
   return this->wishListDam->hasWishList(adopter->getID());
}
vector<Post*>* SearchEngine::getAllPosts()
{
    return this->postDam->getAllPosts();
}
bool SearchEngine::addNewPost(int adopterID, string context, string fileName, int likeNum)
{
    return this->postDam->addNewPost(adopterID, context, fileName, likeNum);
}
string SearchEngine::getAdopterNameByID(int adopterID)
{
    return this->adopterDam->getAdopterNameByID(adopterID);
}
void SearchEngine::likeThePost(Post *post)
{
    this->postDam->likeThePost(post);
}
