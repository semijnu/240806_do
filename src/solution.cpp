class Car {
private:
    string color;
    int year;
    string brand;
    double speed;

public:
    Car(string color, int year, string brand, double speed) : color(color), year(year), brand(brand), speed(speed) {}
    string getColor() { return color; }
    void setColor(string color) { this->color = color; }
    int getYear() { return year; }
    void setYear(int year) { this->year = year; }
    string getBrand() { return brand; }
    void setBrand(string brand) { this->brand = brand; }
    double getSpeed() { return speed; }
    void setSpeed(double speed) { this->speed = speed; }
};

class OffroadCar : public Car {
private:
    string terrain;

public:
    OffroadCar(string color, int year, string brand, double speed, string terrain) : Car(color, year, brand, speed), terrain(terrain) {}
    string getTerrain() { return terrain; }
    void setTerrain(string terrain) { this->terrain = terrain; }
};

int main() {
    Car myCar("Red", 2020, "Toyota", 120.5);
    cout << myCar.getBrand() << endl;

    OffroadCar myOffroadCar("Black", 2021, "Jeep", 140.2, "Rocky");
    cout << myOffroadCar.getTerrain() << endl;
    return 0;
}