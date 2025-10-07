#include <iostream>

using namespace std;


void heapify(int arr[], int n, int index) {
    int maxIndex = index;

    while (true) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < n && arr[leftIndex] > arr[maxIndex]) {
            maxIndex = leftIndex;
        }

        if (rightIndex < n && arr[rightIndex] > arr[maxIndex]) {
            maxIndex = rightIndex;
        }

        if (index != maxIndex) {
            swap(arr[index], arr[maxIndex]);
            index = maxIndex;
        }
        else {
            return;
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int n) {
    //make an array a heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}



int main() {


    int arr[] = { 4, 6, 7, 1, 2, 3, 5 };

    int n = sizeof(arr) / sizeof(arr[0]);


    print(arr, n);

    heapSort(arr, n);

    print(arr, n);


    return 0;
}