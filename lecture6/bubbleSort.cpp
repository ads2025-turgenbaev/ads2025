#include <iostream>

using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}


int main() {

    int arr[] = { 8, 5, 1, 6, 2, 4 };

    int n = sizeof(arr) / sizeof(arr[0]);

    for (auto value : arr) {
        cout << value << " ";
    }

    bubbleSort(arr, n);
    cout << endl;


    for (auto value : arr) {
        cout << value << " ";
    }


    return 0;
}