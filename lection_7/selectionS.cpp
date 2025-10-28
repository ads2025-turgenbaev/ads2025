#include <iostream>

using namespace std;


void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main() {
    int arr[] = { 4, 1, 2, 6, 7, 5, 8, 9 };

    int n = sizeof(arr) / sizeof(arr[0]);


    cout << n << endl;

    selectionSort(arr, n);

    for (auto val : arr) {
        cout << val << " ";
    }

    cout << endl;



    return 0;
}