#include "../project/all.h"
#include <QApplication>
#include <QString>
#include "../GUI/newmenu.h"
#include "../GUI/communitypage.h"
#include "../GUI/cat.h"
#include "../GUI/dog.h"
#include "../GUI/guicontroller.h"
#include <cstdlib>
void generate50SampleAnimals(){
    AnimalDam* animalDam = new AnimalDam();
    string breed1[] = {"Abyssinian","Bobtail", "Bombay"};
    string age1[] = {"kitten", "junior","prime","mature","senior"};
    string size1[]= {"small","medium","large"};
    string coatLength1[] = {"short", "mid-length", "long"};
    string color1[] = {"white","black","grey","orange"};
    string gender1[] = {"Male", "Female"};
    string breeds2[] = {"Alaskan","Labrador","Bulldog","Boxer"};
    string age2[] = {"Puppy", "junior","Adult","senior"};
    for(int i = 0; i < 25; i ++){

        //int num = rand();
        string name = "c" + to_string(i);
        int shelterID = rand() % 3 + 1;
        string species= "Cat";
        string breed = breed1[rand()%3];
        string gender = gender1[rand()%2];
        string age= age2[rand()%4];
        string size= size1[rand()%3];
        string color= color1[rand()%3];
        string coatLength= coatLength1[rand()%3];
        string energylvl = "high";
        int x = rand() % 4 + 1;
        string picLocation = "Cat0" + to_string(x) + ".jpg";

        animalDam->addNewAnimal(shelterID, species, breed, name, gender,age, size, color, coatLength, energylvl, picLocation);

    }
    for(int i = 0; i < 25; i ++){
        string name = "d" + to_string(i);
        int shelterID = i % 3 + 1;
        string species= "Dog";
        string breed = breeds2[rand()%3];
        string gender = gender1[rand()%2];
        string age= age1[rand()%5];
        string size= size1[rand()%3];
        string color= color1[rand()%4];
        string coatLength= coatLength1[rand()%3];
        string energylvl = "high";
        int x = rand() % 4 + 1;
        string picLocation = "Dag0" + to_string(x) + ".jpg";
        animalDam->addNewAnimal(shelterID, species, breed, name, gender,age, size, color, coatLength, energylvl, picLocation);

    }

}
void createAdopter()
{
    AdopterDam* aDam = new AdopterDam();
    aDam->addNewAdopter("124", "ding", "male", 21, "610-559-4763",
                        "dingw@gmail.com", "good", "Los Angeles,California");
    aDam->addNewAdopter("124", "ding", "male", 21, "610-559-4763",
                        "dingw@gmail.com", "good", "Los Angeles,California");
    aDam->addNewAdopter("124", "JoJo", "male", 21, "610-559-4763",
                        "dingw@gmail.com", "good", "Los Angeles,California");
    aDam->addNewAdopter("124", "DING", "male", 21, "610-559-4763",
                        "dingw@gmail.com", "good", "Los Angeles,California");
}

void createEmployees()
{
    EmployeeDam* eDam  = new EmployeeDam();
    eDam->addNewEmployee("111","admin","male",30, 1,"110","help@shelter");
    eDam->addNewEmployee("222","admin2","female",30, 2, "110","help@shelter");
    eDam->addNewEmployee("333","admin3","female",30, 3, "110","help@shelter");
}
void shelterTest(){
    ShelterDam* sDam = new ShelterDam();

    sDam->addNewShelter("shelter1", "Los Angeles,California","100-600","shelter1@.com");
    sDam->addNewShelter("shelter2", "Easton,Pennsylvania","100-600","shelter2@.com");
    sDam->addNewShelter("shelter3", "Chicago,Illinois","100-600","shelter3@.com");

}
void WishListDamTest(){
   WishListDam* wdam = new WishListDam();
//    wdam->addNewWishList(1,"high","d","d","d");
//    wdam->addNewWishList(2,"w","e","v","d");
//    wdam->addNewWishList(1,"high","b","d","d");
  // wdam->getWishListByAdopterID(1)->print();
}
void postTest(){
    PostDam* pDam = new PostDam();
    pDam->addNewPost(1,"hello world","Dog01.jpg",0);
    pDam->addNewPost(1,"hello world agagin","Cog01.jpg",5);
    pDam->addNewPost(1,"hello cat","Cog02.jpg",0);
}
int main(int argc, char *argv[])
{
   //QString build = "sqlite3 ./UserInfo.sqlite <  ../../../../project/build_tables.sql";
    QApplication app(argc, argv);
    Database database("UserInfo.sqlite");
   // generate50SampleAnimals();
    //createAdopter();
  // createEmployees();
    GuiController* gui = new GuiController();
    //shelterTest();
   // postTest();
    //WishListDamTest();
    gui->start();
    return app.exec();


    // Adopter* adopter2 = new Adopter("345", "jojo", "male", 22, "610-559-4763",
    //    "dingw@gmail.com", "good", "MoonStreet");

    return 0;
}
