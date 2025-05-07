
/*In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors
the real-world operations of various account types. The foundation of the system is a base class
representing a generic bank account, encapsulating essential details such as account number and
balance. Building on this foundation, two specialized account types were created: a savings account,
which includes an interest rate as an additional feature, and a current account, which allows an
overdraft limit to accommodate specific customer needs.
To ensure proper initialization and cleanup of account objects, constructors and destructors were
implemented. Essential banking operations such as deposits and withdrawals were made available for
both account types, allowing users to perform and manage their transactions effectively. The system
also accounted for the need to track and manage transaction history, enabling operations such as
undoing the last transaction. This was achieved by simulating a mechanism to store a sequence of
transactions for each account type, providing insight into different ways of managing and organizing
data.*/



#include<iostream>
#include<stack>
using namespace std;

class BankAccount {
protected:
    string AccNumber;
    double Balance;
public:
    BankAccount(string AccNum, double Bla) {
        AccNumber = AccNum;
        Balance = Bla;
    }
    void deposit(double amt) {
        Balance += amt;
        cout << "Deposited " << amt << ", Balance: " << Balance << endl;
    }
    virtual int withdraw(double amt) {
        if (Balance >= amt) {
            Balance -= amt;
            cout << "Withdrawn " << amt << ", Balance: " << Balance << endl;
            return 1;
        } else {
            cout << "Insufficient balance!" << endl;
            return 0;
        }
    }
    double getBalance() const {
        return Balance;
    }
};

class SavingAcc : public BankAccount {
public:
    SavingAcc(string AccNum, double Bla) : BankAccount(AccNum, Bla) {}
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(string AccNum, double Bla, double draftLimit) : BankAccount(AccNum, Bla) {
        overdraftLimit = draftLimit;
    }

    int withdraw(double amt) override {
        if (Balance + overdraftLimit >= amt) {
            Balance -= amt;
            cout << "Withdrawn " << amt << ", Balance: " << Balance << endl;
            return 1;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
            return 0;
        }
    }

    double getDraftLimit() const {
        return overdraftLimit;
    }
};

struct Transaction {
    string type;
    double amt;
};

void showMenu() {
    cout << endl
         << "1. Deposit" << endl
         << "2. Withdraw" << endl
         << "3. Undo" << endl
         << "4. Show Balance" << endl
         << "0. Exit" << endl
         << "Enter choice: ";
}

int main() {
    string type, accNum;
    double bal;

    cout << "Account type (savings/current): ";
    cin >> type;
    cout << "Account number: ";
    cin >> accNum;
    cout << "Initial balance: ";
    cin >> bal;

    stack<Transaction> history;
    int ch;
    double amt;

    if (type == "savings") {
        SavingAcc acc(accNum, bal);

        do {
            showMenu();
            cin >> ch;
            switch (ch) {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"deposit", amt});
                break;

            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt) == 1)
                    history.push({"withdraw", amt});
                break;

            case 3:
                if (!history.empty()) {
                    Transaction last = history.top();
                    history.pop();
                    cout << "Undoing: " << last.type << " of " << last.amt << endl;
                    if (last.type == "deposit") {
                        acc.withdraw(last.amt);
                    } else {
                        acc.deposit(last.amt);
                    }
                } else {
                    cout << "No transaction to undo!" << endl;
                }
                break;

            case 4:
                cout << "Balance: " << acc.getBalance() << endl;
                break;
            }
        } while (ch != 0);

    } else if (type == "current") {
        double limit;
        cout << "Overdraft limit: ";
        cin >> limit;
        CurrentAccount acc(accNum, bal, limit);

        do {
            showMenu();
            cin >> ch;
            switch (ch) {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"deposit", amt});
                break;

            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt) == 1)
                    history.push({"withdraw", amt});
                break;

            case 3:
                if (!history.empty()) {
                    Transaction last = history.top();
                    history.pop();
                    cout << "Undoing: " << last.type << " of " << last.amt << endl;
                    if (last.type == "deposit") {
                        acc.withdraw(last.amt);
                    } else {
                        acc.deposit(last.amt);
                    }
                } else {
                    cout << "No transaction to undo!" << endl;
                }
                break;

            case 4:
                cout << "Balance: " << acc.getBalance() << endl;
                break;
            }
        } while (ch != 0);

    } else {
        cout << "Invalid account type!" << endl;
    }
    cout<<endl<<"24ce119_shreeji";

    return 0;
}


