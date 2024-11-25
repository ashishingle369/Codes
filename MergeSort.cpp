#include <iostream>
using namespace std;

// Function to merge two sorted parts of the array
void merge(int *arr, int start, int end) {
    int mid = (start + end) / 2;

    // Lengths of the two subarrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temporary arrays
    int *leftArray = new int[len1];
    int *rightArray = new int[len2];

    // Copy values to temporary arrays
    int mainIndex = start;
    for (int i = 0; i < len1; i++) {
        leftArray[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        rightArray[i] = arr[mainIndex++];
    }

    // Merge the two sorted arrays back into the main array
    int index1 = 0; // Index for left array
    int index2 = 0; // Index for right array
    mainIndex = start;

    while (index1 < len1 && index2 < len2) {
        if (leftArray[index1] < rightArray[index2]) {
            arr[mainIndex++] = leftArray[index1++];
        } else {
            arr[mainIndex++] = rightArray[index2++];
        }
    }

    // Copy remaining elements of the left array, if any
    while (index1 < len1) {
        arr[mainIndex++] = leftArray[index1++];
    }

    // Copy remaining elements of the right array, if any
    while (index2 < len2) {
        arr[mainIndex++] = rightArray[index2++];
    }

    // Free the temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// Recursive function to perform merge sort
void mergeSort(int *arr, int start, int end) {
    // Base case: if the array has one or no element, it is already sorted
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    // Recursively sort the left half
    mergeSort(arr, start, mid);

    // Recursively sort the right half
    mergeSort(arr, mid + 1, end);

    // Merge the two halves
    merge(arr, start, end);
}

int main() {
    // Array to be sorted
    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;

    cout << "UnSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
