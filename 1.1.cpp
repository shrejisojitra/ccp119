#include <iostream>
#include <string>
using namespace std;
 
class BankAccount {
private:
     string account_holder;
     string account_number;
     double balance;
 
public:
     BankAccount(string holder, string acc_num, double initial_balance = 0) {
         account_holder = holder;
         account_number = acc_num;
         balance = initial_balance;
     }
     void deposit(double amount) {
         if (amount > 0) {
             balance += amount;
             cout << "Successfully deposited $" << amount << ". New balance: $" << balance << endl;
         } else {
             cout << "Deposit amount must be positive." << endl;
         }
     }
     void withdraw(double amount) {
         if (amount > 0) {
             if (balance >= amount) {
                 balance -= amount;
                 cout << "Successfully withdrew $" << amount << ". New balance: $" << balance << endl;
             } else {
                 cout << "Insufficient funds. Withdrawal denied." << endl;
             }
         } else {
             cout << "Withdrawal amount must be positive." << endl;
         }
     }
     void checkBalance() const {
         cout << "Current balance: $" << balance << endl;
     }
     void getAccountDetails() const {
         cout << "Account Holder: " << account_holder << endl;
         cout << "Account Number: " << account_number << endl;
     }
 };
 
 int main() {
     BankAccount account("Aanshi", "123456789", 1000);
     account.getAccountDetails();
     account.deposit(500);
     account.withdraw(200);
     account.withdraw(1500);
     account.checkBalance();
     return 0;
 }
