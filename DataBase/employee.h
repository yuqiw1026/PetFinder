#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
   int EmployeeID;
   string EmployeePW;
   string EmployeeName;

public:
    Employee();
    Employee(int , std::string ,std::string );
    ~Employee();
    int getEmployeeID();
    string getEmployeePW();
    string getEmployeeName();
    void setEmployeeID(int);
    void setEmployeePW(std::string);
    void setEmployeeName(std::string);

};

#endif // EMPLOYEE_H
