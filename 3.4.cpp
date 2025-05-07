#include <iostream>
using namespace std;

template <typename T>
T findMax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

template <typename T>
void displayArray(T* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

template <typename T>
void manageCollection() {
    int size;
    cout << "Enter the size of the collection: ";
    cin >> size;

    T* arr = new T[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "\nOriginal Collection:\n";
    displayArray(arr, size);

    T maxVal = findMax(arr, size);
    cout << "Maximum Value: " << maxVal << endl;

    reverseArray(arr, size);
    cout << "Reversed Collection:\n";
    displayArray(arr, size);

    delete[] arr;
}

int main() {
    int choice;

    do {
        cout << "\n--- Generic Collection Manager ---\n";
        cout << "1. Integer Collection\n";
        cout << "2. Float Collection\n";
        cout << "3. Character Collection\n";
        cout << "0. Exit\n";
        cout << "Choose a collection type: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manageCollection<int>();
                break;
            case 2:
                manageCollection<float>();
                break;
            case 3:
                manageCollection<char>();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
