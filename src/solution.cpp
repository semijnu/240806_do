3. 정답 코드

```C++
#include<iostream>
#include<string>

using namespace std;

class Cars {
    string model_name;
    int price;
    int seat_num;
public:
    Cars(string model, int p, int seat): model_name(model), price(p), seat_num(seat){}

    string getModel_name() { return model_name; }
    int getPrice() { return price; }
    int getSeat_num() { return seat_num; }

    void setModel_name(string model) { model_name = model; }
    void setPrice(int p) { price = p; }
    void setSeat_num(int seat) { seat_num = seat; }

    string showInfo() {
        return "Model: " + model_name + ", Price: " + to_string(price) + ", Seats: " + to_string(seat_num);
    }
};

int main(){
    Cars car("BMW", 50000, 4);
    cout << car.showInfo() << endl; 

    car.setModel_name("Mercedes");
    car.setPrice(45000);
    car.setSeat_num(2);

    cout << "Model: "<< car.getModel_name() << ", Price: " << car.getPrice() << ", Seats: " << car.getSeat_num() << "\n";
    cout << car.showInfo() << endl; 
    return 0;
}
```