2. 문제 코드(프로그램의 대략적인 구조를 보여주는 기본 코드)
```c++
#include<iostream>
#include<string>

class BankAccount {
private:
    std::string accountName;
    int balance;

public:
    // Constructor
    BankAccount(std::string name, int initialBalance);

    // Member functions
    void deposit(int amount);
    void withdraw(int amount);
};

int main() {
    // Create an object of BankAccount
    BankAccount myAccount("My Account", 1000);

    // Test deposit function
    myAccount.deposit(?);

    // Test withdraw function
    myAccount.withdraw(?);

    return 0;
}
```