#include <iostream>
 #include <string>
 using namespace std;
 const int MAX_ACCOUNTS = 10;
 class BankAccount {
 private:
     string accountHolder;
     string accountNumber;
     double balance;
 
 public:
     BankAccount(string holder, string accNumber, double initialBalance) {
         accountHolder = holder;
         accountNumber = accNumber;
         balance = initialBalance;
     }
     BankAccount(string holder, string accNumber) {
         accountHolder = holder;
         accountNumber = accNumber;
         balance = 0.0;
     }
     void deposit(double amount) {
         if (amount > 0) {
             balance += amount;
             cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
         } else {
             cout << "Invalid deposit amount." << endl;
         }
     }
     bool withdraw(double amount) {
         if (amount <= 0) {
             cout << "Invalid withdrawal amount." << endl;
             return false;
         } else if (amount > balance) {
             cout << "Insufficient funds. Withdrawal denied." << endl;
             return false;
         } else {
             balance -= amount;
             cout << "Withdrew: $" << amount << ". New balance: $" << balance << endl;
             return true;
         }
     }
     void displayAccountSummary() const {
         cout << "Account Holder: " << accountHolder << endl;
         cout << "Account Number: " << accountNumber << endl;
         cout << "Current Balance: $" << balance << endl;
     }
     string getAccountNumber() const {
         return accountNumber;
     }
 };
 class BankSystem {
 private:
     BankAccount* accounts[MAX_ACCOUNTS];
     int accountCount; 
 public:
     BankSystem() : accountCount(0) {}
     bool createAccount(string holder, string accNumber, double initialBalance) {
         if (accountCount >= MAX_ACCOUNTS) {
             cout << "Account limit reached. Cannot create new account." << endl;
             return false;
         }
         accounts[accountCount] = new BankAccount(holder, accNumber, initialBalance);
         accountCount++;
         cout << "Account created successfully for " << holder << " with account number " << accNumber << "." << endl;
         return true;
     }
     bool createAccount(string holder, string accNumber) {
         if (accountCount >= MAX_ACCOUNTS) {
             cout << "Account limit reached. Cannot create new account." << endl;
             return false;
         }
         accounts[accountCount] = new BankAccount(holder, accNumber);
         accountCount++;
         cout << "Account created successfully for " << holder << " with account number " << accNumber << " and zero balance." << endl;
         return true;
     }
     BankAccount* findAccountByNumber(string accNumber) {
         for (int i = 0; i < accountCount; i++) {
             if (accounts[i]->getAccountNumber() == accNumber) {
                 return accounts[i];
             }
         }
         return nullptr; 
     }
 
     // Display all account summaries
     void displayAllAccounts() const {
         if (accountCount == 0) {
             cout << "No accounts found." << endl;
             return;
         }
         for (int i = 0; i < accountCount; i++) {
             accounts[i]->displayAccountSummary();
         }
     }
     ~BankSystem() {
         for (int i = 0; i < accountCount; i++) {
             delete accounts[i]; 
         }
     }
 };
 
 int main() {
     BankSystem bank;
     bank.createAccount("John Doe", "1001", 500.0);
     bank.createAccount("Alice Smith", "1002");
     bank.createAccount("Bob Johnson", "1003", 1000.0);
     BankAccount* account = bank.findAccountByNumber("1001");
     if (account != nullptr) {
         account->deposit(200.0);      
         account->withdraw(100.0);    
         account->withdraw(700.0);    
         }
     bank.displayAllAccounts();
 
     return 0;
 }
