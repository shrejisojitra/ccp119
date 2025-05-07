#include <iostream>
using namespace std;

class Student {
private:
    int roll, marks[3];
    string name;
    float avg;

public:
    // Default constructor
    Student() {
        roll = 0;
        name = "N/A";
        marks[0] = marks[1] = marks[2] = 0;
        avg = 0.0;
    }

    // Parameterized constructor
    Student(int rno, string nam, int mar1, int mar2, int mar3) {
        roll = rno;
        name = nam;
        marks[0] = mar1;
        marks[1] = mar2;
        marks[2] = mar3;
    }

    // Function to display student details
    void display() {
        cout << "Roll No: " << roll << endl;
        cout << "Name   : " << name << endl;
        cout << "Marks of CCP               : " << marks[0] << endl;
        cout << "Marks of Maths             : " << marks[1] << endl;
        cout << "Marks of Digital Electronics: " << marks[2] << endl;
    }

    // Function to calculate and display average marks
    void avgg() {
        avg = (marks[0] + marks[1] + marks[2]) / 3.0;
        cout << "Average of marks is: " << avg << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int roll, mark1, mark2, mark3;
        string name;

        cout << "\nEnter Roll No: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks of CCP: ";
        cin >> mark1;

        cout << "Enter Marks of Maths: ";
        cin >> mark2;

        cout << "Enter Marks of Digital Electronics: ";
        cin >> mark3;

        Student obj(roll, name, mark1, mark2, mark3);

        cout << "\nTHE DATA OF STUDENT " << i + 1 << ":\n";
        obj.display();
        obj.avgg();
    }


    return 0;
}
