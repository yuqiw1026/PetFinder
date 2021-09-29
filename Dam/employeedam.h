#ifndef EMPLOYEEDAM_H
#define EMPLOYEEDAM_H

#include <string>
#include <QtSql>
#include <vector>
#include "../DataBase/UserInfo/employee.h"

using namespace std;

class EmployeeDam
{
private:
    int recordTo;
    vector<Employee*> employees;
public:
    EmployeeDam();
    void write();
    void read();
    void remove(int employeeID);
    bool add(Employee* employee);

    bool addNewEmployee(string passWord, string userName, string gender,
                        int age, int shelterID,string phoneNumber, string email);
    bool hasEmployee(Employee* employee);
    void printAll();

    int login(string userName, string passWord);
    bool hasName(string userName);
    Employee* getEmployeeByName(string name);
};

#endif // EMPLOYEEDAM_H
