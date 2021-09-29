#ifndef POSTDAM_H
#define POSTDAM_H

#include <string>
#include <QtSql>
#include <vector>
#include "../DataBase/post.h"

using namespace std;

class PostDam
{
private:
    int recordTo;
    vector<Post*> posts;
public:
    PostDam();

    /**
    * @brief insert post information to the database
    */
    void write();

    /**
    * @brief get post information from the database and store it in post class,
    * then put it into the vector "posts"
    */
    void read();
    void remove(int postID);
    //void add(Post* post);
    bool hasPost(Post* post);
    void printAll();
    void insertOnePost(Post* post);
    bool addNewPost(int AdopterID, string context, string fileName, int likeNum);
    vector<Post*>* getAllPosts();
    void likeThePost(Post *post);
};
#endif // POSTDAM_H
