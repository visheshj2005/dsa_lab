// #include <iostream>
// using namespace std;

// void linearSearch(int arr[], int n, int key) {
//     bool found = false;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == key) {
//             cout << "Element " << key << " found at position " << i << endl;
//             found = true;
//             break;
//         }
//     }
//     if (!found) {
//         cout << "Element " << key << " not found in the array" << endl;
//     }
// }

// int main() {
//     int arr[] = {2, 4, 5, 7, 1, 3, 8, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int key = 5;
    
//     cout << "Performing Linear Search:" << endl;
//     linearSearch(arr, n, key);

//     return 0;
// }
#include <iostream>
using namespace std;

void binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            cout << "Element " << key << " found at position " << mid << endl;
            return;
        }

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "Element " << key << " not found in the array" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    
    cout << "Performing Binary Search:" << endl;
    binarySearch(arr, 0, n - 1, key);

    return 0;
}
