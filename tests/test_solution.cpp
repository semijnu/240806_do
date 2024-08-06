4. 테스트 케이스
```
// Test Case 1:
BankAccount myAccount1("My Account", 1000);
myAccount1.deposit(500);
myAccount1.withdraw(200);
myAccount1.withdraw(2000);
// Expected Output: 
// Deposit Successful. New balance is: 1500
// Withdrawal Successful. New balance is: 1300
// Insufficient balance. Withdrawal failed.

// Test Case 2:
BankAccount myAccount2("My Account", 2000);
myAccount2.deposit(1000);
myAccount2.withdraw(500);
myAccount2.withdraw(3000);
// Expected Output: 
// Deposit Successful. New balance is: 3000
// Withdrawal Successful. New balance is: 2500
// Insufficient balance. Withdrawal failed.

// Test Case 3:
BankAccount myAccount3("My Account", 5000);
myAccount3.deposit(5000);
myAccount3.withdraw(2500);
myAccount3.withdraw(7500);
// Expected Output: 
// Deposit Successful. New balance is: 10000
// Withdrawal Successful. New balance is: 7500
// Insufficient balance. Withdrawal failed.
```