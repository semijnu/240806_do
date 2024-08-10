#include <iostream>
#include <string>
using namespace std;

class Employee
{
    private:
    string name;
    double salary;
    int hiredYear;

    public:
    Employee(string n, double s, int h) {
        name = n;
        salary = s;
        hiredYear = h;
    }
    string getName() {
        return name;
    }
    double getSalary() {
        return salary;
    }
    int getHiredYear() {
        return hiredYear;
    }
    void raiseSalary(double percent) {
        salary += salary * percent / 100;
    }
};

int main() {
    Employee employees[3] = {
        Employee("John Doe", 50000, 2000),
        Employee("Jane Smith", 60000, 2005),
        Employee("Jim Brown", 70000, 2010)
    };

    for (int i=0; i<3; i++) {
        cout << "Employee name: " << employees[i].getName() << "\n";
        cout << "Salary before raise: " << employees[i].getSalary() << "\n";
        employees[i].raiseSalary(10.0);
        cout << "Salary after 10% raise: " << employees[i].getSalary() << "\n\n";
    }

    return 0;
}