#ifndef COMMUNITY_H
#define COMMUNITY_H


#include <string>
#include <QtSql>
#include <iostream>
#include <vector>

using namespace std;

class Community
{
private:
    int communityID;
    string name;
    int numOfPost;
    void setName(string cname);
public:
    Community(int cmntyID);
    Community(int cmntyID,string cname);
    void setNumOfPost(int numValue);
    int getCommunityID();
    string getName();
    int getNumOfPost();
    void print();
};

#endif // COMMUNITY_H
