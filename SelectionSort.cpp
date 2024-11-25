#include <iostream>
using namespace std;

int main() {
    int n, i, j, minIndex;

    // Input: size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Input: elements of the array
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display the original array
    cout << "Original array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";

    // Selection Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        // Assume the first unsorted element is the minimum
        minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first unsorted element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Display the sorted array
    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] <<  "\t";
    }
    cout << endl;

    return 0;
}
