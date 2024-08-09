2. 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드)
```c++
#include <iostream>
#include <string>

// Employee 클래스입니다.
class Employee {
    private:
        std::string name; // 직원의 이름
        std::string position; // 직원의 직책
        double salary; // 직원의 급여
    public:
        Employee(std::string n, std::string p, double s) {
            // 생성자를 완성하세요.
        }

        void display() {
            // 이 함수는 직원 정보를 출력합니다.
        }
};

int main() {
    std::string name;
    std::string position;
    double salary;

    // 사용자로부터 직원 정보를 입력 받습니다.
    std::cout << "Employee's name: ";
    std::cin >> name;
    std::cout << "Employee's position: ";
    std::cin >> position;
    std::cout << "Employee's salary: ";
    std::cin >> salary;

    // Employee 객체를 생성하고, 직원 정보를 출력합니다.
    Employee employee(name, position, salary);
    employee.display();

    return 0;
}
```