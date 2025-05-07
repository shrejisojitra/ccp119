#include <iostream>
using namespace std;

class ArrayAnalyzer {
private:
    int* arr;
    int size;

public:
    ArrayAnalyzer(int s) {
        size = s;
        arr = new int[size];
    }

    void inputElements() {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    int recursiveSum(int index = 0) {
        if (index == size)
            return 0;
        return arr[index] + recursiveSum(index + 1);
    }

    int iterativeSum() {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return sum;
    }

    void displayResults() {
        cout << "\nSum using Recursive Approach: " << recursiveSum() << endl;
        cout << "Sum using Iterative Approach: " << iterativeSum() << endl;
    }

    ~ArrayAnalyzer() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    ArrayAnalyzer analyzer(size);
    analyzer.inputElements();
    analyzer.displayResults();

    return 0;
}
