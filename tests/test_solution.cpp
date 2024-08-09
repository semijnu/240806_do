```C++
#include<iostream>
#include<string>

class Student{
private:
    std::string name;
    int id;
    int* score;
public:
    // 코드를 작성하시오.

};

int main(){
    int N;
    std::cin >> N;
    Student s("John Doe", 12345, N);
    for(int i=0; i<N; i++){
        int x;
        std::cin >> x;
        s.set_score(i, x);
    }

    s.print_student_info();

    return 0;
}
```