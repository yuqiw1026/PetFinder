#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include "all.h"
#include "../Dam/traitdam.h"
#include "../DataBase/Location/filereader.h"
#include <algorithm>
#include <map>
using namespace  std;
class SearchEngine
{
private:
    AdopterDam* adopterDam;
    EmployeeDam* employeeDam;
    AnimalDam* animalDam;
    ShelterDam* shelterDam;
    TagDam* tagDam;
    TraitDam* traitDam;
    OrderDam* orderDam;
    WishListDam* wishListDam;
    PostDam* postDam;

public:
    FileReader* myfileReader;
    SearchEngine();

    SearchEngine(AdopterDam* adopterDam, EmployeeDam* employeeDam, AnimalDam* animalDam,
                 ShelterDam* shelterDam, TagDam* tagDam, TraitDam* traitDam);
    AdopterDam* getAdopterDam();
    vector<Animal*>* getAnimalsByIDs(vector<int>* ids);
    vector<Animal*>* getAllFromOneSpecies(string speciesName);

    vector<Animal*>* searchForOneInOneSpecies(string species,string traitName, string context);
    int getShelterIDByAnimalID(int animalID);
    vector<Order*>* getAllWaitingOrdersInOneShelter(int shelterID);
    map<double, Animal*>* sortAnimalsOrderByDistance(vector<Animal*>* original, Adopter* adopter);
    double getDistanceBetweenAnimalandAdopter(Animal* animal, Adopter* adopter);
    void insertIntoMap(map<double, Animal*>* temp, double distance, Animal* animal);
    string getShelterAddressByID(int shelterID);
    vector<string>* getPreferencesByAdopterID(int adopterID);
    bool addNewWishList(Adopter* adopter, string energyLevel, string coatLength, string color, string size);
    bool adopterhasWishList(Adopter* adopter);
    vector<Post*>* getAllPosts();
    bool addNewPost(int AdopterID, string context, string fileName, int likeNum);
    string getAdopterNameByID(int adopterID);
    void likeThePost(Post* post);
};

#endif // SEARCHENGINE_H
