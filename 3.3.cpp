#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    static int totalAccounts;
    int accountNumber;
    string holderName;
    double balance;

public:
    Account() {
        accountNumber = 0;
        holderName = "";
        balance = 0.0;
    }

    void create(int accNum, const string& name, double initialBalance) {
        accountNumber = accNum;
        holderName = name;
        balance = initialBalance;
        totalAccounts++;
    }

    int getAccountNumber() const { return accountNumber; }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name   : " << holderName << endl;
        cout << "Balance       : $" << balance << endl;
        //cout << "-----------------------------" << endl;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    bool transferTo(Account& receiver, double amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            return true;
        }
        return false;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

// Find account by account number
Account* findAccount(Account* accounts, int size, int accNum) {
    for (int i = 0; i < size; ++i) {
        if (accounts[i].getAccountNumber() == accNum)
            return &accounts[i];
    }
    return nullptr;
}

int main() {
    int maxAccounts = 100;
    Account* accounts = new Account[maxAccounts];
    int accountCount = 0;
    int choice;

    do {
        cout << "\n--- Community Bank System ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Funds\n";
        cout << "4. Show Total Accounts\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            if (accountCount >= maxAccounts) {
                cout << "Account limit reached!\n";
                continue;
            }

            int accNum;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder's Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts[accountCount].create(accNum, name, balance);
            accountCount++;
            cout << "Account created successfully.\n";

        } else if (choice == 2) {
            cout << "\n-- Account List --\n";
            for (int i = 0; i < accountCount; ++i) {
                accounts[i].display();
            }

        } else if (choice == 3) {
            int fromAcc, toAcc;
            double amount;

            cout << "Enter Sender Account Number: ";
            cin >> fromAcc;
            cout << "Enter Receiver Account Number: ";
            cin >> toAcc;
            cout << "Enter Amount to Transfer: ";
            cin >> amount;

            Account* sender = findAccount(accounts, accountCount, fromAcc);
            Account* receiver = findAccount(accounts, accountCount, toAcc);

            if (sender && receiver) {
                if (sender->transferTo(*receiver, amount)) {
                    cout << "Transfer successful!\n";
                } else {
                    cout << "Transfer failed! Insufficient balance.\n";
                }
            } else {
                cout << "Invalid account number(s).\n";
            }

        } else if (choice == 4) {
            cout << "Total number of accounts: " << Account::getTotalAccounts() << endl;
        }

    } while (choice != 0);

    delete[] accounts;
    cout << "Thank you for using Community Bank System!\n";
    return 0;
}
