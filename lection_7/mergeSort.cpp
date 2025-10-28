#include <iostream>

using namespace std;

void merge(int arr[], int leftIndex, int midIndex, int rightIndex) {
    int leftArrSize = midIndex - leftIndex + 1;
    int rightArrSize = rightIndex - midIndex;

    int leftArray[leftArrSize];
    int rightArray[rightArrSize];

    for (int i = 0; i < leftArrSize; i++) {
        leftArray[i] = arr[leftIndex + i];
    }

    for (int j = 0; j < rightArrSize; j++) {
        rightArray[j] = arr[midIndex + 1 + j];
    }

    int i = 0;
    int j = 0;
    int index = leftIndex;

    while (i < leftArrSize && j < rightArrSize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[index] = leftArray[i];
            index++;
            i++;
        }
        else {
            arr[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArrSize) {
        arr[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArrSize) {
        arr[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) {
        return;
    }

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(arr, leftIndex, midIndex);
    mergeSort(arr, midIndex + 1, rightIndex);

    merge(arr, leftIndex, midIndex, rightIndex);
}


int main() {

    int arr[] = { 3, 2, 1, 5, 6, 7, 8 };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (auto val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}