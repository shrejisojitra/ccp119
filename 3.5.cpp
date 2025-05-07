#include <iostream>
#include <string>

using namespace std;

long long sumOfDigits(const string& numStr) {
    long long sum = 0;
    for (char digit : numStr) {
        sum += digit - '0';
    }
    return sum;
}

int superDigit(long long num) {
    if (num < 10)
        return num;

    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return superDigit(sum);
}

int main() {
    string n;
    int k;

    cout << "Enter the number (n): ";
    cin >> n;
    cout << "Enter the repetition factor (k): ";
    cin >> k;

    // Step 1: Sum digits of n
    long long initialSum = sumOfDigits(n);

    // Step 2: Multiply sum by k
    long long total = initialSum * k;

    // Step 3: Find super digit
    int result = superDigit(total);

    cout << "Super Digit: " << result << endl;

    return 0;
}
