#ifndef WISHLISTDAM_H
#define WISHLISTDAM_H
#include <string>
#include <QtSql>
#include "../DataBase/wishlist.h"

using namespace std;

class WishListDam
{
private:
    int recordTo;
    vector<WishList*> wishLists;
public:
    WishListDam();
    void write();
    void read();
    void add(WishList* wishList);
    bool hasWishList(WishList* wishList);
    bool hasWishList(int adopterID);
    void printAll();
    bool addNewWishList(int adoptorID, string energyLevel, string coatLength, string color, string size);
    WishList* getWishListByAdopterID(int adopterID);
    void insertOneWishList(WishList* wishList);
    vector<string>* getPreferencesByAdopterID(int id);
};

#endif // WISHLISTDAM_H
