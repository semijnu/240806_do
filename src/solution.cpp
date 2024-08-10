아래와 같은 형태가 될 수 있지만, 다른 방식으로 작성하는 것도 가능합니다.

#include <iostream>
#include <vector>
#include <string>
#include <numeric>  // gcd() 함수를 위해
#include <sstream>  // 문자열 처리를 위해
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int n, int d): numerator(n), denominator(d) {
        int gcd = std::gcd(n, d);
        numerator /= gcd;
        denominator /= gcd;
    }

    Fraction operator+(const Fraction& f) {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    string str() {
        stringstream ss;
        ss << numerator << '/' << denominator;
        return ss.str();
    }
};

string sumOfFractions(vector<string> fractions) {
    Fraction sum(0, 1);
    for (auto& s: fractions) {
        stringstream ss(s);
        int n, d;
        char c;
        ss >> n >> c >> d;
        sum = sum + Fraction(n, d);
    }
    return sum.str();
}

int main() {
    vector<string> fractions;
    string input;
    while(cin >> input) {
        fractions.push_back(input);
    }
    cout << "Sum of fractions is: " << sumOfFractions(fractions);
    return 0;
}