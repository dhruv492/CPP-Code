#include <iostream>
using namespace std;

class Employee
{
    char name[50];
    double basicSalary;
    double bonus;

public:
    Employee(const char* empName, double empBasicSalary, double empBonus = 5000.0)
    {
        int i = 0;
        while (empName[i] != '\0' && i < 49) {
            name[i] = empName[i];
            i++;
        }
        name[i] = '\0';

        basicSalary = empBasicSalary;
        bonus = empBonus;
    }

    double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "---------------------------------" << endl;
    }
};

int main() {
    const int numEmployees = 3;
    Employee employees[numEmployees] = {
        Employee("Alice", 50000),
        Employee("Bob", 55000, 10000),
        Employee("Charlie", 60000, 15000)
    };

    cout << "Employee Records:" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        employees[i].displayDetails();
    }

    return 0;
}
