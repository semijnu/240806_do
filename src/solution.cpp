3. 정답 코드
```cpp
#include<iostream>
#include<string>

using namespace std;

class Car{
    string brand;
    string color;
    double price;
public:
    void setBrand(string b){
        brand = b;
    }
    void setColor(string c){
        color = c;
    }
    void setPrice(double p){
        price = p;
    }
    void checkInfo(){
        if(brand.empty() || color.empty() || price == 0){
            cout<<"정보가 누락되었습니다! 브랜드, 색상, 가격을 모두 입력하세요!";
        }
        else{
            cout<<"모든 정보가 탑재 되었습니다!";
        }
    }
};

int main()
{
    Car myCar;
    myCar.setBrand("Toyota");
    myCar.setColor("Red");
    myCar.setPrice(20000);
    myCar.checkInfo();
    
    return 0;
}
```