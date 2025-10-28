#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j > -1 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main() {
    int arr[] = { 4, 1, 2, 6, 7, 5, 8, 9 };

    int n = sizeof(arr) / sizeof(arr[0]);


    cout << n << endl;

    insertionSort(arr, n);

    for (auto val : arr) {
        cout << val << " ";
    }

    cout << endl;



    return 0;
}