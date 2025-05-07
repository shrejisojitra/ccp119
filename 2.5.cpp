#include <iostream>
 #include <cmath>
 #include <string>
 
 using namespace std;
 class Loan {
 private:
     string applicantName;
     int loanID;
     double loanAmount;
     double annualInterestRate;
     int loanTenureInMonths;
     double EMI;
 
 public:
     Loan() {
         applicantName = "Unknown";
         loanID = 0;
         loanAmount = 0.0;
         annualInterestRate = 0.0;
         loanTenureInMonths = 0;
         EMI = 0.0;
     }
     Loan(int id, string name, double amount, double rate, int tenure) {
         loanID = id;
         applicantName = name;
         loanAmount = amount;
         annualInterestRate = rate;
         loanTenureInMonths = tenure;
         EMI = calculateEMI();
     }
     double calculateEMI() {
         double monthlyInterestRate = annualInterestRate / 12 / 100; // Monthly interest rate
         double emi = (loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, loanTenureInMonths)) / 
                      (pow(1 + monthlyInterestRate, loanTenureInMonths) - 1);
         return emi;
     }
     void displayLoanDetails() {
         cout << "\nLoan Details for Applicant: " << applicantName << endl;
         cout << "Loan ID: " << loanID << endl;
         cout << "Loan Amount: " << loanAmount << endl;
         cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
         cout << "Loan Tenure: " << loanTenureInMonths << " months" << endl;
         cout << "EMI: " << EMI << endl;
     }
     void setLoanAmount(double amount) {
         loanAmount = amount;
         EMI = calculateEMI(); // Recalculate EMI after amount change
     }
 
     void setAnnualInterestRate(double rate) {
         annualInterestRate = rate;
         EMI = calculateEMI(); // Recalculate EMI after rate change
     }
 
     void setLoanTenureInMonths(int tenure) {
         loanTenureInMonths = tenure;
         EMI = calculateEMI(); // Recalculate EMI after tenure change
     }
 };
 
 int main() {
     int loanID;
     string name;
     double amount, rate;
     int tenure;
     cout << "Enter Loan ID: ";
     cin >> loanID;
     cin.ignore(); 
     cout << "Enter Applicant Name: ";
     getline(cin, name);
     cout << "Enter Loan Amount: ";
     cin >> amount;
     cout << "Enter Annual Interest Rate (in %): ";
     cin >> rate;
     cout << "Enter Loan Tenure (in months): ";
     cin >> tenure;
     Loan loan(loanID, name, amount, rate, tenure);
     loan.displayLoanDetails();
     return 0;
 }
