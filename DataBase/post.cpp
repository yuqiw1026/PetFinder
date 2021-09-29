#include "post.h"

vector<Post*> posts;


Post::Post(int postID, int adopterID, string context, string fileName, int likeNum){
    this->postID = postID;
    this->adopterID = adopterID;
    this->context = context;
    this->fileName = fileName;
    this->likeNum = likeNum;
}

int Post::getPostID(){
    return postID;
}


/**
* @brief print information of a post, post id, user id and community section id.
*/
void Post::print()
{
    cout << this->getPostID() << " | " << this->adopterID << " | " << this->likeNum << endl;

}
