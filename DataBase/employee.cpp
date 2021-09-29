#include "employee.h"
#include <string>
Employee::Employee()
{

}


Employee::Employee(int ID, std::string pw,std::string n)
{
     this->EmployeeID   = ID;
      this->EmployeePW = pw;
     this-> EmployeeName= n;

}

Employee::~Employee() {

//delete this->EmployeeID;
}

int Employee::getEmployeeID(){
    return this->EmployeeID;
}
std::string Employee::getEmployeePW(){
    return this->EmployeePW;
}
std::string Employee::getEmployeeName(){
    return this->EmployeeName;
}

void Employee::setEmployeeID(int id){
 this->EmployeeID=id;
}
void Employee::setEmployeePW(std::string pw){
  this->EmployeePW=pw;
}
void Employee::setEmployeeName(std::string n){
   this->EmployeeName=n;
}
