#include <iostream>
#include "gtest/gtest.h"
#include <string>
using namespace std;
#include "../Application/DataBase/UserInfo/adopter.h"
#include "../Application/DataBase/UserInfo/adopter.cpp"
#include "../Application/DataBase/UserInfo/user.h"
#include "../Application/DataBase/searchengine.h"
#include "../Application/DataBase/database.h"
#include "../Application/DataBase/animal.h"
#include "../Application/DataBase/community.h"
#include "../Application/DataBase/UserInfo/adopter.h"
#include "../Application/DataBase/UserInfo/user.h"
#include "../Application/DataBase/tag.h"
#include "../Application/DataBase/shelter.h"
#include "../Application/DataBase/wishlist.h"
#include "../Application/DataBase/order.h"
#include "../Application/DataBase/post.h"
#include "../Application/DataBase/trait.h"
#include "../Application/DataBase/recommendedlist.h"
#include "../Application/DataBase/UserInfo/employee.h"
#include "../Application/Dam/wishlistdam.h"
#include "../Application/Dam/adopterdam.h"
#include "../Application/Dam/tagdam.h"
#include "../Application/Dam/shelterdam.h"
#include "../Application/Dam/orderdam.h"
#include "../Application/Dam/employeedam.h"
#include "../Application/Dam/recommendedlistdam.h"
#include "../Application/Dam/animaldam.h"
#include "../Application/Dam/traitdam.h"
#include "../Application/Dam/postdam.h"
/**
 * @brief Handles SnakeEngine class tests.
 */
class UnitTest: public ::testing::Test {};

// there are 50 animals in the test.sqlite
// id from 1 - 25 are cats
// id from 26 - 50 are dogs

/**
 * @brief TEST  test if the searchEngine can get all cats inside of the database
 */
TEST(UnitTest, test1GettingAllCats) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->getAllFromOneSpecies("Cat");
    for(int i = 0; i < 25; i++){
        ASSERT_EQ(i+1, (*temp)[i]->getID());
    }

}
/**
 * @brief TEST  test if the searchEngine can get all cats inside of the database
 */
TEST(UnitTest, test2GettingAllDogs) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->getAllFromOneSpecies("Dog");
    for(int i = 0; i < 25; i++){
        ASSERT_EQ(i+26, (*temp)[i]->getID());
    }
}

TEST(UnitTest, test3GettingAllCatsWithBreedBombay) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Cat","Breed", "Bombay");
    for(int i = 0; i < temp->size(); i++){
        ASSERT_EQ("Bombay", (*temp)[i]->breed);
    }
}

TEST(UnitTest, test4GettingAllCatWithBreedBobtail) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Cat","Breed", "Bobtail");
    for(int i = 0; i < temp->size(); i++){
        ASSERT_EQ("Bobtail", (*temp)[i]->breed);
    }
}

TEST(UnitTest, test5GettingAllCatWithBreedAbyssinian) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Cat","Breed", "Abyssinian");
    for(int i = 0; i < temp->size(); i++){
        ASSERT_EQ("Abyssinian", (*temp)[i]->breed);
    }
}

TEST(UnitTest, test6GettingAllDogWithBreedAlaskan) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Dog","Breed", "Alaskan");
    for(int i = 0; i < temp->size(); i++){
        ASSERT_EQ("Alaskan", (*temp)[i]->breed);
    }
}

TEST(UnitTest, test7GettingAllDogWithBreedLabrador) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Dog","Breed", "Labrador");
    for(int i = 0; i < temp->size(); i++){
        ASSERT_EQ("Labrador", (*temp)[i]->breed);
    }
}

TEST(UnitTest, test8GettingAllDogWithBreedBulldog) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Dog","Breed", "Bulldog");
    for(int i = 0; i < temp->size(); i++){
        ASSERT_EQ("Bulldog", (*temp)[i]->breed);
    }
}

TEST(UnitTest, test9CheckNumOfCatWithBreedBombay) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Cat","Breed", "Bombay");
    QSqlQuery qry;
    string s = "select count() from Animal where Breed == \"Bombay\"; ";
    qry.exec(QString::fromStdString(s));
    int num = -1;
    if(qry.next()){
        num = qry.value(0).toInt();
    }
    ASSERT_EQ(num,temp->size());
}

TEST(UnitTest, test10CheckNumOfCatWithBreedBobtail) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Cat","Breed", "Bobtail");
    QSqlQuery qry;
    string s = "select count() from Animal where Breed == \"Bobtail\"; ";
    qry.exec(QString::fromStdString(s));
    int num = -1;
    if(qry.next()){
        num = qry.value(0).toInt();
    }
    ASSERT_EQ(num,temp->size());
}

TEST(UnitTest, test11CheckNumOfCatWithBreedAbyssinian) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Cat","Breed", "Abyssinian");
    QSqlQuery qry;
    string s = "select count() from Animal where Breed == \"Abyssinian\"; ";
    qry.exec(QString::fromStdString(s));
    int num = -1;
    if(qry.next()){
        num = qry.value(0).toInt();
    }
    ASSERT_EQ(num,temp->size());
}

TEST(UnitTest, test12CheckNumOfDogWithBreedAlaskan) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Dog","Breed", "Alaskan");
    QSqlQuery qry;
    string s = "select count() from Animal where Breed == \"Alaskan\"; ";
    qry.exec(QString::fromStdString(s));
    int num = -1;
    if(qry.next()){
        num = qry.value(0).toInt();
    }
    ASSERT_EQ(num,temp->size());
}

TEST(UnitTest, test13CheckNumOfDogWithBreedLabrador) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Dog","Breed", "Labrador");
    QSqlQuery qry;
    string s = "select count() from Animal where Breed == \"Labrador\"; ";
    qry.exec(QString::fromStdString(s));
    int num = -1;
    if(qry.next()){
        num = qry.value(0).toInt();
    }
    ASSERT_EQ(num,temp->size());
}

TEST(UnitTest, test14CheckNumOfDogWithBreedBulldog) {
    SearchEngine* searchEngine = new SearchEngine();
    vector<Animal*>* temp = searchEngine->searchForOneInOneSpecies("Dog","Breed", "Bulldog");
    QSqlQuery qry;
    string s = "select count() from Animal where Breed == \"Bulldog\"; ";
    qry.exec(QString::fromStdString(s));
    int num = -1;
    if(qry.next()){
        num = qry.value(0).toInt();
    }
    ASSERT_EQ(num,temp->size());
}
TEST(UnitTest, test15CheckGetAdopterNameByID) {
    SearchEngine* searchEngine = new SearchEngine();
    string name = searchEngine->getAdopterNameByID(1);
    string name2 = searchEngine->getAdopterNameByID(2);
    string name3 = searchEngine->getAdopterNameByID(3);
    ASSERT_EQ(name,"ding");
    ASSERT_EQ(name2,"JoJo");
    ASSERT_EQ(name3,"DING");
}
TEST(UnitTest, test16CheckGetShelterAddressByID) {
    SearchEngine* searchEngine = new SearchEngine();
    string address = searchEngine->getShelterAddressByID(1);
    string address2 = searchEngine->getShelterAddressByID(2);
    string address3 = searchEngine->getShelterAddressByID(3);
    ASSERT_EQ(address,"Los Angeles,California");
    ASSERT_EQ(address2,"Easton,Pennsylvania");
    ASSERT_EQ(address3,"Chicago,Illinois");
}
TEST(UnitTest, test17CheckLikeThePost) {
    SearchEngine* searchEngine = new SearchEngine();
    QSqlQuery qry;
    string s = "select * from Post where PostID = 1; ";
    Post* post;
    int likeNum = -1;
    qry.exec(QString::fromStdString(s));
    if(qry.next()){
        int postId = qry.value("PostID").toInt();
        int adopterID = qry.value("AdopterID").toInt();
        string context = qry.value("Context").toString().toStdString();
        string fileName = qry.value("FileName").toString().toStdString();
        likeNum = qry.value("LikeNum").toInt();
        post = new Post(postId, adopterID, context, fileName, likeNum);
    }
    if(post != nullptr && likeNum != -1){
        searchEngine->likeThePost(post);
    }
    vector<Post*>* posts = searchEngine->getAllPosts();
    ASSERT_EQ((*posts)[0]->likeNum, likeNum + 1);

}

/**
 * @brief main  main method to run all tests
 * @param argc  integer argument
 * @param argv  string argument
 * @return  exit code (0 for success)
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    Database database("test.sqlite");
    return RUN_ALL_TESTS();
}
