#include "community.h"

Community::Community(int cmntyID)
{
    communityID = cmntyID;
}

Community::Community(int cmntyID,string cname)
{
    communityID = cmntyID;
    name = cname;
}

void Community::setName(string cname){
    name = cname;
}

void Community::setNumOfPost(int numValue){
    numOfPost = numValue;
}

int Community::getCommunityID(){
    return communityID;
}

string Community::getName(){
    return name;
}

int Community::getNumOfPost(){
    return numOfPost;
}

/**
* @brief print information of a community section: community id, community name and
* total number of posts in it.
*/
void Community::print()
{
    cout << this->getCommunityID() << " | " << this->getName() << " | " << this->getNumOfPost() << endl;
}
