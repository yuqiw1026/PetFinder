#ifndef RECOMMENDEDLISTDAM_H
#define RECOMMENDEDLISTDAM_H
#include "../DataBase/recommendedlist.h"
#include <vector>
#include <QtSql>
using namespace std;
class RecommendedListDam
{
private:
    vector<RecommendedList*> recommendedLists;
    int recordTo;
public:
    RecommendedListDam();
    void write();
    void read();
    void add(RecommendedList* recommendedList);
    bool hasRecoomendedList(RecommendedList* recommendedList);
    void printAll();
    vector<int>* getAllRecommended(int adopterID);
};

#endif // RECOMMENDEDLISTDAM_H
