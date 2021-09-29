#include "guicontroller.h"
#include "../DataBase/searchengine.h"
GuiController::GuiController()
{
    myAnimalDam = new AnimalDam();
    myOrderDam = new OrderDam();


    myFileReader = new FileReader();
    myFileReader->read();
    mySearchEngine = new SearchEngine();
    mySearchEngine->myfileReader = myFileReader;
    myMenu = new NewMenu();
    myresultanimal = new ResultAnimal(nullptr, myOrderDam);
    myCat = new Cat(nullptr, myFileReader,mySearchEngine,myresultanimal);
    myDog = new Dog(nullptr, myFileReader,mySearchEngine);

    myCommunity = new CommunityPage(0, mySearchEngine);
    myLogind = new Logind();
    myAbout = new aboutpage();
    myPref = new mypreference(0,mySearchEngine);
    myWishlist = new mywishlist();
    myOrder =new adopterorder(0,myOrderDam);

    EOrder = new employeeorder(0,myOrderDam,mySearchEngine);
    myOther = new Other(nullptr, myFileReader,mySearchEngine);
    myAccount = new AccountInfo(nullptr, myFileReader);
    myAnimal=new AnimalInfos(nullptr, myAnimalDam);
    myMenu->logindPage = myLogind;
    myMenu->cpage = myCommunity;
    myMenu->accountInfoPage = myAccount;
    myMenu->catPage = myCat;
    myMenu->dogPage = myDog;
    myMenu->otherPage = myOther;
    myMenu->employeeOrderPage = EOrder;
    myMenu->myPrefPage = myPref;
    myAccount->myAdopterDam = myAdopterDam;
    myMenu->adopterOderPage = myOrder;
    myPost = new NewPost();

    myRegisterPage = new Regispage(nullptr, myFileReader);
    myAdopterDam = mySearchEngine->getAdopterDam();
    myRegisterPage->myAdopterDam = myAdopterDam;

    user = 0;

    QObject::connect(myMenu,SIGNAL(comshow()),myCommunity,SLOT(comReceiveshow()));
    QObject::connect(myCommunity,SIGNAL(comShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(catshow()),myCat,SLOT(catReceiveshow()));
    QObject::connect(myCat,SIGNAL(catShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myCat,SIGNAL(anmresltshow()),myresultanimal,SLOT(reltanmReceiveshow()));

    QObject::connect(myMenu,SIGNAL(aboutshow()),myAbout,SLOT(aboutReceiveshow()));
    QObject::connect(myAbout,SIGNAL(aboutShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(dogshow()),myDog,SLOT(dogReceiveshow()));
    QObject::connect(myDog,SIGNAL(dogShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(logindShow()),myLogind,SLOT(logindReceivesShow()));
    QObject::connect(myLogind,SIGNAL(logindShowmainwindow()),myMenu,SLOT(receiveLogind()));


    QObject::connect(myLogind,SIGNAL(logindSHowNewMenuWithoutLogin()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(prefshow()),myPref,SLOT(prefReceivesshow()));
    QObject::connect(myPref,SIGNAL(prefShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(wishlistshow()),myWishlist,SLOT(wishlistReceivesshow()));
    QObject::connect(myWishlist,SIGNAL(wlShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(hideAddressComboBox()),myCat,SLOT(recevieHideAddressComboBox()));
    QObject::connect(myMenu,SIGNAL(reShowAddressComboBox()),myCat,SLOT(recevieShowAddressComboBox()));




    QObject::connect(myMenu,SIGNAL(adopterordershow()),myOrder,SLOT(adopterorderReceivesshow()));
    QObject::connect(myOrder,SIGNAL(adopterorderShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(employeeordershow()),EOrder,SLOT(employeeorderReceivesshow()));
    QObject::connect(EOrder,SIGNAL(employeeorderShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(othershow()),myOther,SLOT(otherReceiveshow()));
    QObject::connect(myOther,SIGNAL(otherShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(accountshow()),myAccount,SLOT(accountReceiveshow()));
    QObject::connect(myAccount,SIGNAL(accountShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myMenu,SIGNAL(anminfoshow()),myAnimal,SLOT(anminfoReceiveshow()));
    QObject::connect(myAnimal,SIGNAL(anminfoShowmainwindow()),myMenu,SLOT(newMenueReceivesShow()));

    QObject::connect(myLogind,SIGNAL(logindShowRegister()),myRegisterPage,SLOT(registerReceivesShow()));
    QObject::connect(myRegisterPage,SIGNAL(registerShowLogind()),myLogind,SLOT(logindReceivesShow()));

    QObject::connect(myRegisterPage,SIGNAL(registerShowNewMenue()),myMenu,SLOT(newMenueReceivesShow()));


    //Translate part

    //AccountInfo
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myAccount,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myAccount,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myAccount,SIGNAL(translateToSpanish()),myMenu,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myAccount,SIGNAL(translateToEnglish()),myMenu,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myAccount,SIGNAL(translateToSpanish()),myCat,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myAccount,SIGNAL(translateToEnglish()),myCat,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myAccount,SIGNAL(translateToSpanish()),myDog,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myAccount,SIGNAL(translateToEnglish()),myDog,SLOT(receivesTranslateToEnglish()));

     //Cat
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myCat,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myCat,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myCat,SIGNAL(translateToSpanish()),myMenu,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myCat,SIGNAL(translateToEnglish()),myMenu,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myCat,SIGNAL(translateToSpanish()),myAccount,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myCat,SIGNAL(translateToEnglish()),myAccount,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myCat,SIGNAL(translateToSpanish()),myDog,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myCat,SIGNAL(translateToEnglish()),myDog,SLOT(receivesTranslateToEnglish()));

     //Dog
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myDog,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myDog,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myDog,SIGNAL(translateToSpanish()),myMenu,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myDog,SIGNAL(translateToEnglish()),myMenu,SLOT(receivesTranslateToEnglish()));

     QObject::connect(myDog,SIGNAL(translateToSpanish()),myCat,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myDog,SIGNAL(translateToEnglish()),myCat,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myDog,SIGNAL(translateToSpanish()),myAccount,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myDog,SIGNAL(translateToEnglish()),myAccount,SLOT(receivesTranslateToEnglish()));

     //Other
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myOther,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myOther,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myOther,SIGNAL(translateToSpanish()),myMenu,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myOther,SIGNAL(translateToEnglish()),myMenu,SLOT(receivesTranslateToEnglish()));

     //Community
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myCommunity,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myCommunity,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myCommunity,SIGNAL(translateToSpanish()),myMenu,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myCommunity,SIGNAL(translateToEnglish()),myMenu,SLOT(receivesTranslateToEnglish()));

     //Post
     QObject::connect(myCommunity,SIGNAL(translateToSpanish()),myPost,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myCommunity,SIGNAL(translateToEnglish()),myPost,SLOT(receivesTranslateToEnglish()));

     //Login
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myLogind,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myLogind,SLOT(receivesTranslateToEnglish()));


     //Register
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myRegisterPage,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myRegisterPage,SLOT(receivesTranslateToEnglish()));
     //Preference
     QObject::connect(myMenu,SIGNAL(translateToSpanish()),myPref,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myMenu,SIGNAL(translateToEnglish()),myPref,SLOT(receivesTranslateToEnglish()));
     QObject::connect(myPref,SIGNAL(translateToSpanish()),myMenu,SLOT(receivesTranslateToSpanish()));
     QObject::connect(myPref,SIGNAL(translateToEnglish()),myMenu,SLOT(receivesTranslateToEnglish()));

     //Orders&Request part

     //employees would have a shared orderRequest page
     QObject::connect(myresultanimal,SIGNAL(adoptrequestsent()),EOrder,SLOT(receiverequest()));
     //Todo:user would receive the request signal & different content of requests created depend on userID
   //  QObject::connect(EOrder,SIGNAL(requestCreatedEmp()),myOrder,SLOT(receiveRequestCreated()));



}


void GuiController::start()
{
    this->myMenu->show();
    //cout << this->myFileReader->distanceEarth("Los Angeles,California", "Austin,Texas") << endl;
    //mySearchEngine->getAllFromOneSpecies("Cat");
}
