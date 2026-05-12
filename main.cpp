#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ===================== FUNCTIONS =====================

void calculateAverages(int* arr, int size) {
    if (size <= 0) { cout << "Empty array!\n"; return; }

    int sumEven = 0, countEven = 0;
    int sumOdd = 0, countOdd = 0;

    int* ptr = arr;
    int* end = arr + size;

    while (ptr < end) {
        if (*ptr % 2 == 0) {
            sumEven += *ptr; countEven++;
        } else {
            sumOdd += *ptr; countOdd++;
        }
        ptr++;
    }

    cout << "\n=== Average of even and odd numbers ===\n";
    if (countEven > 0)
        cout << "Average of even numbers: " << fixed << setprecision(2) 
             << (double)sumEven / countEven << endl;
    else cout << "There are no even numbers.\n";

    if (countOdd > 0)
        cout << "Average odd: " << (double)sumOdd / countOdd << endl;
    else cout << "There are no paired numbers\n";
}

void findLongestAndShortest(string* arr, int size) {
    if (size <= 0) { cout << "Empty array!\n"; return; }

    string* longest = arr;
    string* shortest = arr;

    for (int i = 1; i < size; ++i) {
        string* ptr = arr + i;
        if (ptr->length() > longest->length()) longest = ptr;
        if (ptr->length() < shortest->length()) shortest = ptr;
    }

    cout << "\n=== Longest and shortest line ===\n";
    cout << "The longest: \"" << *longest << "\" (length = " << longest->length() << ")\n";
    cout << "Shortest: \"" << *shortest << "\" (length = " << shortest->length() << ")\n";
}

void sumReverse(double* arr, int size) {
    if (size <= 0) { cout << "Empty array!\n"; return; }

    double sum = 0.0;
    double* ptr = arr + size - 1;

    while (ptr >= arr) {
        sum += *ptr;
        ptr--;
    }

    cout << "\n=== Sum of elements (reverse order) ===\n";
    cout << "Sum = " << fixed << setprecision(2) << sum << endl;
}

// ===================== MENU =====================
int main() {
    setlocale(LC_ALL, "uk_UA");

    while (true) {
        cout << "\n========================================\n";
        cout << "     Practical work #14 - Indicators\n";
        cout << "========================================\n";
        cout << "1. Average of even and odd numbers\n";
        cout << "2. Longest and shortest line\n";
        cout << "3. Sum of elements in reverse order\n";
        cout << "0. Entrance\n";
        cout << "----------------------------------------\n";
        cout << "Your choice: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > 3) {
            cout << "Wrong choice!\n";
            continue;
        }

        int size;
        cout << "Enter the array size: ";
        cin >> size;

        if (choice == 1) {
            int* arr = new int[size];
            cout << "Enter " << size << " integers:\n";
            for (int i = 0; i < size; i++) cin >> arr[i];
            calculateAverages(arr, size);
            delete[] arr;
        }
        else if (choice == 2) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string* arr = new string[size];
            cout << "Enter " << size << " lines:\n";
            for (int i = 0; i < size; i++) {
                getline(cin, arr[i]);
            }
            findLongestAndShortest(arr, size);
            delete[] arr;
        }
        else if (choice == 3) {
            double* arr = new double[size];
            cout << "Enter " << size << " real numbers:\n";
            for (int i = 0; i < size; i++) cin >> arr[i];
            sumReverse(arr, size);
            delete[] arr;
        }
    }

    cout << "Program completed.\n";
    return 0;
}
