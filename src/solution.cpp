3. 정답 코드
```cpp
#include <iostream>
using namespace std;

class Polygon {
private:
    int sides[10];  
    int numberOfSides;
public:
    void setSides() {
        cout << "Enter the number of sides: ";
        cin >> numberOfSides;
        for(int i=0; i<numberOfSides; i++) {
            cout << "Enter the length of side " << i+1 << ": ";
            cin >> sides[i];
        }
    }
    
    int perimeter() {
        int total = 0;
        for(int i=0; i<numberOfSides; i++) {
            total += sides[i];
        }
        return total;
    }
    
    void display() {
        for(int i=0; i<numberOfSides; i++) {
            cout << "Length of side " << i+1 << ": " << sides[i] << endl;
        }
    }
};

int main() {
    Polygon p;
    p.setSides();
    cout << "Perimeter: " << p.perimeter() << endl;
    p.display(); 
    return 0;
}
```