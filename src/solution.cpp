3. 정답 코드
```c++
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string major;
    int id;
    double grade;

public:
    Student() {;}
    Student(string _name, string _major, int _id, double _grade)
        : name(_name), major(_major), id(_id), grade(_grade) {;}

    void showInfo() {
        cout << "Name: " << name << endl;
        cout << "Major: " << major << endl;
        cout << "ID: " << id << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    string name, major;
    int id;
    double grade;

    cin >> name >> major >> id >> grade;

    Student std1(name, major, id, grade);

    std1.showInfo();

    return 0;
}
```