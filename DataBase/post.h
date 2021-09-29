#ifndef POST_H
#define POST_H

#include <string>
#include <QtSql>
#include <iostream>
#include <vector>

using namespace std;

class Post
{
private:

public:
    int postID;
    int adopterID;
    string context;
    int likeNum;
    string fileName;
    Post(int postID, int adopterID, string context, string fileName, int likeNum);
    int getPostID();
    void print();
};

#endif // POST_H
