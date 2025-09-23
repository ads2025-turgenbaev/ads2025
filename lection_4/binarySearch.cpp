#include <iostream>

using namespace std;


bool binarySearch(vector<int>& arr, int value) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (value == arr[mid]) {
            return true;
        }

        if (value > arr[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}



int main() {
    vector<int> arr = { 1, 3, 5, 7, 9, 13, 23 };

    int target = 6;

    cout << binarySearch(arr, target);
    return 0;
}