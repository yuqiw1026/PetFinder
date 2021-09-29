#include "adopterdam.h"

AdopterDam::AdopterDam()
{
    this->recordTo = 0;
    this->read();
}

void AdopterDam::read()
{
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select AdopterID from Adopter;")) {
        qDebug() << query.lastError();
    }
//AdopterID, Password, Name, Gender, Age, PhoneNumber, Email, LivingCondition, Address
    while (query.next()) {
        int id = query.value("AdopterID").toInt();
        if (id > (int)recordTo) {
            recordTo = id;
        }
    }
}
//retrun int
//0 for repeated userName
int AdopterDam::add(Adopter *adopter)
{
    if(!hasAdopter(adopter)){
        insertOneAdopter(adopter);
        return 1;
    }else{
        cout << "This adopter has been added!" << endl;
        return 0;
    }
}

void AdopterDam::insertOneAdopter(Adopter *adopter)
{
    QSqlQuery query;

    query.prepare("INSERT INTO Adopter (AdopterID, Password, Name, Gender, Age, PhoneNumber, Email, LivingCondition, Address) "
               "VALUES (:AdopterID, :Password, :Name, :Gender, :Age, :PhoneNumber, :Email, :LivingCondition, :Address);");
       // Bind values for the adopter
           if (adopter->getID() > recordTo) {
               query.bindValue(":AdopterID", adopter->getID());
               query.bindValue(":Password", QString::fromStdString(adopter->getPassWord()));
               query.bindValue(":Name", QString::fromStdString(adopter->getUserName()));
               query.bindValue(":Gender", QString::fromStdString(adopter->getGender()));
               query.bindValue(":Age", adopter->getAge());
               query.bindValue(":PhoneNumber", QString::fromStdString(adopter->getPhoneNo()));
               query.bindValue(":Email", QString::fromStdString(adopter->getEmail()));
               query.bindValue(":LivingCondition", QString::fromStdString(adopter->getLivingCondition()));
               query.bindValue(":Address", QString::fromStdString(adopter->getAddress()));
               recordTo = adopter->getID();
               if (!query.exec()) {
                   qDebug() << query.lastError();
                  // cout << "???" <<endl;
               }
           }
}


bool AdopterDam::hasAdopter(Adopter *adopter)
{
    string temp = "select * from Adopter where AdopterID = \"" + to_string(adopter->getID()) + "\"" + "or Name = \""+ adopter->getUserName() + "\";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
            //cout << "it has this Adopter already" << endl;
            return true;
        }
        //cout << "it does not have this Adopter" << endl;
    return false;
}
void AdopterDam::printAll()
{

}

// return int
// 0 for wrong password
// 1 for No such user
// 2 for success
int AdopterDam::loggin(string userName, string passWord)
{
    string temp = "select * from Adopter where Name = \"" + userName + "\";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
            string password = query.value("Password").toString().toStdString();
            if(passWord == password){
                return 2;
            }else{
                return 0;
            }

        }else{
            return 1;
        }
}

Adopter* AdopterDam::getAdopterByName(string name){
    QSqlQuery query;
    // Check for errors
    string s = "select * from Adopter where Name = \"" +name +"\";";
    if (!query.exec(QString::fromStdString(s))) {
        qDebug() << query.lastError();
    }

    if (query.next()) {
        int id = query.value("AdopterID").toInt();
        string password = query.value("Password").toString().toStdString();
        string userName = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int age = query.value("Age").toInt();
        string phoneNo = query.value("PhoneNumber").toString().toStdString();
        string email = query.value("Email").toString().toStdString();
        string livCon = query.value("LivingCondition").toString().toStdString();
        string address = query.value("Address").toString().toStdString();

        Adopter* adopter = new Adopter(id, password, userName, gender, age, phoneNo, email,livCon, address);
        return adopter;
    }
    return nullptr;
}


bool AdopterDam::addNewAdopter(string passWord, string userName, string gender, int age, string phoneNumber, string email, string livingCondition, string address)
{
    cout << "Adopter RecordTo: " << recordTo << endl;
    Adopter* adopter = new Adopter(recordTo+1,passWord, userName, gender, age,phoneNumber,email,livingCondition, address);
    if(!this->hasAdopter(adopter)){
        insertOneAdopter(adopter);
        return true;
    }
    return false;
}
// 0 for wrong passWd
// 2 for two passwords does not match
int AdopterDam::updateIndividual(Adopter *oldAdopter, string newUserName, string newGender, int newAge, string newPhoneNo, string newEmail, string currentPasswd, string newPasswd, string newPasswd2, string newCity, string newState)
{
    if(newUserName != ""){
        oldAdopter->userName = newUserName;
    }

    if(newPhoneNo != ""){
       oldAdopter->setPhoneNo(newPhoneNo);
    }
    if(newGender != ""){
        oldAdopter->gender = newGender;
    }
    if(newEmail != ""){
        oldAdopter->email = newEmail;
    }
    if(newAge != 0){
        oldAdopter->age = newAge;
    }
    if(currentPasswd!= ""){
        if(oldAdopter->getPassWord() == currentPasswd){
            if(newPasswd == newPasswd2 && newPasswd != ""){
                oldAdopter->passWord = newPasswd;
            }else{
                return 2;
            }
        }else{
            return 0;
        }
    }
   // cout << newState << " " << newCity << endl;
    string oldAddress = oldAdopter->getAddress();
    vector<string> result;
    stringstream s_stream(oldAddress); //create string stream from the string
    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        result.push_back(substr);
    }
    if(newCity != "" || newState != ""){
        if(newCity != ""){
            result[1] = newCity;
        }
        if(newState != ""){
            result[0] = newState;
        }
    }
    string newAddress = result[1] + "," + result[0];
    oldAdopter->address = newAddress;
    QSqlQuery query;

    query.prepare("update Adopter set Name = :Name, Password = :Password, Gender = :Gender, "
                  "Age = :Age, PhoneNumber = :PhoneNumber, "
                  "Email = :Email, Address = :Address where AdopterID = :adopterID;");
    query.bindValue(":Name", QString::fromStdString(oldAdopter->getUserName()));
    query.bindValue(":Password", QString::fromStdString(oldAdopter->getPassWord()));

    query.bindValue(":Gender", QString::fromStdString(oldAdopter->getGender()));
    query.bindValue(":Age", oldAdopter->getAge());
    query.bindValue(":PhoneNumber", QString::fromStdString(oldAdopter->getPhoneNo()));
    query.bindValue(":Email", QString::fromStdString(oldAdopter->getEmail()));
    query.bindValue(":Address", QString::fromStdString(oldAdopter->getAddress()));
    query.bindValue(":adopterID", oldAdopter->getID());
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "something is wrong when editing adopter info" <<endl;
    }
    return 1;
}

string AdopterDam::getAdopterNameByID(int adotperID)
{
    string temp = "select Name from Adopter where AdopterID = " + to_string(adotperID) + ";";
    QSqlQuery query;
        // Check for errors
        if (!query.exec(QString::fromStdString(temp))) {
            qDebug() << query.lastError();
        }
        if(query.next()){
            string name = query.value("Name").toString().toStdString();
            return  name;
        }else{
            return "";
        }
}
