#include "postdam.h"

PostDam::PostDam()
{
    this->recordTo = 0;
    this->read();
}

/**
* @brief insert post information to the database
*/
void PostDam::write()
{
    // Assemble query
 QSqlQuery query;

 query.prepare("INSERT INTO Post (postID, communityID, userID) "
            "VALUES (:postID, :communityID, :userID);");
    // Bind values for the post
    for (unsigned int i = 0; i < posts.size(); i++) {
        Post* post = posts[i];
        // Only insert new posts
        if (post->getPostID() > recordTo) {
            query.bindValue(":postID", post->getPostID());

            recordTo = post->getPostID();
            cout << "!!!!!" << endl;
            if (!query.exec()) {
                qDebug() << query.lastError();
                cout << "???" <<endl;
            }
        }
    }
}

/**
* @brief get post information from the database and store it in post class,
* then put it into the vector "posts"
*/
void PostDam::read()
{
    QSqlQuery query;

    // Check for errors
    if (!query.exec("select PostID from Post;")) {
        qDebug() << query.lastError();
    }

    while (query.next()) {
        // Read the attributes of the next post record
        int postId = query.value("PostID").toInt();
//        int adopterID = query.value("AdopterID").toInt();
//        string context = query.value("Context").toString().toStdString();
//        string fileName = query.value("FileName").toString().toStdString();
//        int likeNum = query.value("LikeNum").toInt();
        //Post* post = new Post(postId,communityId, userId);
     //   posts.push_back(post);
        // Update the existing ID threshold
        if (postId > recordTo) {
            recordTo = postId;
        }
    }

}

void PostDam::remove(int postID){
    for (unsigned int i = 0; i < posts.size(); i++)
    {
        if(posts[i]->getPostID() == postID){
            posts.erase(posts.begin() + i);
            break;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Post WHERE Post.postID ==?");
    query.addBindValue(postID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

/**
* @brief print all posts from the vector collecting all post information
*/
void PostDam::printAll(){
    for (unsigned int i = 0; i < posts.size(); i++)
    {
        posts[i]->print();
    }
}


bool PostDam::hasPost(Post *post)
{
    QSqlQuery query;
    string s = "select * from Post where PostID = " + to_string(post->getPostID())+  " ;";
    // Check for errors
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }

    if (query.next()) {
        cout << "the post eixts already" << endl;
        return true;
    }
    return false;
}
void PostDam::insertOnePost(Post* post)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Post (PostID, AdopterID, Context, FileName, LikeNum) "
                  "VALUES (:PostID, :AdopterID, :Context, :FileName, :LikeNum);");
    // Bind values for the post
    // Only insert new posts

    query.bindValue(":PostID", post->postID);
    query.bindValue(":AdopterID", post->adopterID);
    query.bindValue(":Context", QString::fromStdString(post->context));
    query.bindValue(":FileName", QString::fromStdString(post->fileName));
    query.bindValue(":LikeNum", post->likeNum);

    if (!query.exec()) {
        qDebug() << query.lastError();
    }
cout << "adding one post" <<endl;
    if (post->getPostID() > recordTo) {
        recordTo = post->getPostID();
    }
}
bool PostDam::addNewPost(int adopterID, string context, string fileName, int likeNum)
{
    Post* post = new Post(recordTo + 1, adopterID, context, fileName, likeNum);
    if(!hasPost(post)){
        insertOnePost(post);
        return true;
    }
    return false;
}
vector<Post*>* PostDam::getAllPosts()
{
    vector<Post*>* temp = new vector<Post*>();
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select * from Post;")) {
        qDebug() << query.lastError();
    }

    while (query.next()) {
        // Read the attributes of the next post record
        int postId = query.value("PostID").toInt();
        int adopterID = query.value("AdopterID").toInt();
        string context = query.value("Context").toString().toStdString();
        string fileName = query.value("FileName").toString().toStdString();
        int likeNum = query.value("LikeNum").toInt();
        Post* post = new Post(postId,adopterID,context,fileName,likeNum);
        temp->push_back(post);
    }
    return temp;
}

void PostDam::likeThePost(Post *post)
{
    QSqlQuery query;
    string s = "update Post set LikeNum = " + to_string(post->likeNum + 1) + " where PostID = " + to_string(post->getPostID())+  " ;";
    // Check for errors
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }
}
