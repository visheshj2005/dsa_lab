#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &size, int element, int position) {
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
}

void deleteElement(int arr[], int &size, int position) {
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
}

int main() {
    int arr1[20], arr2[10], merged[30];
    int size1, size2, element, position;

    cout << "Enter the number of elements in the first array: ";
    cin >> size1;
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in the second array: ";
    cin >> size2;
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    cout << "First array: ";
    displayArray(arr1, size1);

    cout << "Second array: ";
    displayArray(arr2, size2);

    // Insertion
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert the element: ";
    cin >> position;
    insertElement(arr1, size1, element, position);
    cout << "Array after insertion: ";
    displayArray(arr1, size1);

    // Deletion
    cout << "Enter the position to delete the element: ";
    cin >> position;
    deleteElement(arr1, size1, position);
    cout << "Array after deletion: ";
    displayArray(arr1, size1);

    // Merging
    mergeArrays(arr1, size1, arr2, size2, merged);
    cout << "Merged array: ";
    displayArray(merged, size1 + size2);

    return 0;
}
