#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H
#include "../project/all.h"
#include <QApplication>
#include <QString>
#include "newmenu.h"
#include "communitypage.h"
#include "cat.h"
#include "dog.h"
#include "logind.h"
#include "aboutpage.h"
#include "mypreference.h"
#include "other.h"
#include "accountinfo.h"
#include "mywishlist.h"
#include "animalinfos.h"
#include "../GUI/resultanimal.h"
#include "mywishlist.h"
#include "adopterorder.h"
#include "employeeorder.h"
#include "detailorder.h"
#include "payment.h"
#include "../DataBase/searchengine.h"
#include "../project/all.h"
#include "../DataBase/Location/filereader.h"
#include "../Dam/orderdam.h"
class GuiController
{
private:
    int user; //0 if no info, 1 for Adopter, 2 for Employee
    NewMenu* myMenu;
    Cat* myCat;
    Dog* myDog;
    ResultAnimal* myresultanimal;
    CommunityPage* myCommunity;
    //Adopter* myAdopter;
    //Employee* myEmployee;
    Logind* myLogind;
    aboutpage* myAbout;
    mypreference* myPref;
    adopterorder* myOrder;
    DetailOrder* mydetail;
    employeeorder* EOrder;
    mywishlist* myWishlist;
    Other* myOther;
    AccountInfo* myAccount;
    AnimalInfos* myAnimal;
    Regispage* myRegisterPage;
    NewPost* myPost;
    OrderDam* myOrderDam;

    AdopterDam* myAdopterDam;
    AnimalDam* myAnimalDam;
    SearchEngine* mySearchEngine;

    FileReader* myFileReader;

public:
    GuiController();
    void start();
};

#endif // GUICONTROLLER_H
