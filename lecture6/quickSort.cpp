#include <iostream>

using namespace std;


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int pivot(int arr[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;

    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        if (arr[i] < arr[pivotIndex]) {
            swapIndex++;
            swap(arr[swapIndex], arr[i]);
        }
    }

    swap(arr[pivotIndex], arr[swapIndex]);

    return swapIndex;
}

void quickSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) {
        return;
    }

    int pivotIndex = pivot(arr, leftIndex, rightIndex);

    quickSort(arr, leftIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, rightIndex);
}

int main() {
    int arr[] = { 4, 6, 7, 1, 2, 3, 5 };


    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);


    cout << " pivot index: " << pivot(arr, 0, n - 1) << endl;

    quickSort(arr, 0, n - 1);


    print(arr, n);


    return 0;
}