#include "tagdam.h"

TagDam::TagDam()
{
    this->recordTo = 0;
    this->read();
}

void TagDam::read()
{
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select * from Tag;")) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        int id = query.value("ID").toInt();
        string name = query.value("Name").toString().toStdString();
        string content = query.value("Content").toString().toStdString();
        Tag* tag = new Tag(id, name, content);
        tags.push_back(tag);
        // Update the existing ID threshold
        if (id > (int)recordTo) {
            recordTo = id;
        }
    }
}

bool TagDam::add(Tag* tag)
{
    if(!hasTag(tag)){
        tags.push_back(tag);
        return true;
    }
    return false;
}

bool TagDam::hasTag(Tag *tag)
{
    for (unsigned int i = 0; i < tags.size(); i++)
    {
        if(tags[i]->getTagName() == tag->getTagName()){
            if(tags[i]->getTagContent() == tag->getTagContent()){
                return true;
            }
        }
    }
    return false;
}

void TagDam::printAll()
{
    for (unsigned int i = 0; i < tags.size(); i++)
    {
        tags[i]->print();
    }

}
void TagDam::write()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Tag (ID, Name, Content) VALUES (:ID, :Name, :Content);");

    for (unsigned int i = 0; i < tags.size(); i++) {
        Tag* tag = tags[i];
        // Only insert new adopters
        if (tag->getID() > recordTo) {
            query.bindValue(":ID", tag->getID());
            query.bindValue(":Name", QString::fromStdString(tag->getTagName()));
            query.bindValue(":Content", QString::fromStdString(tag->getTagContent()));
            recordTo++;
            if (!query.exec()) {
                qDebug() << query.lastError();

            }
        }
    }
}


void TagDam::remove(int tagID){
    for (unsigned int i = 0; i < tags.size(); i++)
    {
        if(tags[i]->getID() == tagID){
            tags.erase(tags.begin() + i);
            break;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Tag WHERE Tag.ID ==?");
    query.addBindValue(tagID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

int TagDam::getSpecificTag(string tagName, string tagContent)
{
    for(unsigned int i = 0; i < tags.size(); i++){
        Tag* tag = tags[i];
        if(tag->getTagName() == tagName && tag->getTagContent() == tagContent){
            return tag->getID();
        }
    }
    return  0;
}

bool TagDam::addNewTag(string tagName, string tagContent)
{
    cout << "recordTo: " << recordTo << endl;
    Tag* tag = new Tag(recordTo+1,tagName, tagContent);
    cout << "success "  << endl;
    if(this->add(tag)){
        this->write();
        return true;
    }
    return false;
}
