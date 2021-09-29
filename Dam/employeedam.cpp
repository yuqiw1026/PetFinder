#include "employeedam.h"

EmployeeDam::EmployeeDam()
{
    this->recordTo = 0;
    this->read();
}


void EmployeeDam::read()
{
    QSqlQuery query;
    // Check for errors
    if (!query.exec("select * from Employee;")) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        int id = query.value("ID").toInt();
        string password = query.value("Password").toString().toStdString();
        string name = query.value("Name").toString().toStdString();
        string gender = query.value("Gender").toString().toStdString();
        int age = query.value("Age").toInt();
        int shelterID = query.value("ShelterID").toInt();
        string phoneNo = query.value("PhoneNumber").toString().toStdString();
        string email = query.value("Email").toString().toStdString();
        //TODO
        Employee* employee = new Employee(id, password, name,gender,age,shelterID, phoneNo,email);
        employees.push_back(employee);
        // Update the existing ID threshold
        if (id > recordTo) {
            recordTo = id;
        }
    }
}

bool EmployeeDam::add(Employee* employee)
{
    if(!hasEmployee(employee)){
        employees.push_back(employee);
        return true;
    }
    return false;
}

bool EmployeeDam::addNewEmployee(string passWord, string userName, string gender,
int age,int shelterID, string phoneNumber, string email)
{
    cout << "Employee RecordTo: " << recordTo << endl;
    Employee* employee = new Employee(recordTo+1,passWord, userName, gender, age, shelterID, phoneNumber,email);
    if(this->add(employee)){
        this->write();
        return true;
    }
    return false;
}


bool EmployeeDam::hasEmployee(Employee *employee)
{
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        if(employees[i]->getID() == employee->getID() || employees[i]->getUserName() == employee->getUserName()){
            return true;
        }
    }
    return false;
}
void EmployeeDam::printAll()
{
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        employees[i]->print();
    }

}
void EmployeeDam::write()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Employee (ID, Password, Name, Gender, Age, ShelterID, PhoneNumber, Email) "
"VALUES (:ID, :Password, :Name, :Gender, :Age, :ShelterID, :PhoneNumber, :Email);");

    for (unsigned int i = 0; i < employees.size(); i++) {
        Employee* employee = employees[i];
        // Only insert new adopters
        if (employee->getID() > recordTo) {
            query.bindValue(":ID", employee->getID());
            query.bindValue(":Password", QString::fromStdString(employee->getPassWord()));
            query.bindValue(":Name",  QString::fromStdString(employee->getUserName()));
            query.bindValue(":Gender", QString::fromStdString(employee->getGender()));
            query.bindValue(":Age", employee->getAge());
            query.bindValue(":ShelterID", employee->getShelterID());
            query.bindValue(":PhoneNumber", QString::fromStdString(employee->getPhoneNo()));
            query.bindValue(":Email", QString::fromStdString(employee->getEmail()));
            recordTo++;
            if (!query.exec()) {
                qDebug() << query.lastError();
            }
        }
    }
}

void EmployeeDam::remove(int employeeID){
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        if(employees[i]->getID() == employeeID){
            employees.erase(employees.begin() + i);
            break;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Employee WHERE Employee.ID ==?");
    query.addBindValue(employeeID);
    if (!query.exec()) {
        qDebug() << query.lastError();
        cout << "??Problem!" <<endl;
    }
}

// return int
// 0 for wrong password
// 1 for No such user
// 2 for success

int EmployeeDam::login(string userName, string passWord)
{
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        if(employees[i]->getUserName() == userName){
            if(employees[i]->getPassWord() == passWord){
                //cout << "Welcome Back " << userName << "!" << endl;
                return 2;
            }else{
               // cout << "Wrong Password!" << endl;
                return 0;
            }
        }
    }
    //cout << "No such User!" << endl;
    return 1;
}

bool EmployeeDam::hasName(string userName)
{
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        if(employees[i]-> getUserName() == userName){
             cout << "The User Name has been Registered!" << endl;
             return false;
        }
    }
    return true;
}
Employee* EmployeeDam::getEmployeeByName(string name){
    for (unsigned int i = 0; i < employees.size(); i++)
    {
        if(employees[i]->getUserName() == name){
             return employees[i];
        }
    }
    return NULL;
}
