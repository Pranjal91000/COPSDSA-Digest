#include <iostream>

using namespace std;

int main() {
    // 1D Array Operations
    int size = 5;
    int arr[size] = {3, 7, 1, 4, 6};

    // Displaying the original 1D array
    cout << "Original 1D Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Accessing Elements in 1D Array
    int element = arr[2];
    cout << "Element at index 2 in 1D Array: " << element << endl;

    // Insertion in 1D Array
    arr[1] = 9; // Update element at index 1
    cout << "1D Array after updating element at index 1: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deletion in 1D Array
    // Let's remove the element at index 3
    for (int i = 3; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--; // Update array size
    cout << "1D Array after deleting element at index 3: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Searching in 1D Array
    int key1D = 6;
    bool found1D = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key1D) {
            found1D = true;
            cout << "Element " << key1D << " found at index " << i << " in 1D Array." << endl;
            break;
        }
    }
    if (!found1D) {
        cout << "Element " << key1D << " not found in the 1D array." << endl;
    }

    // Traversal of 1D Array
    cout << "1D Array traversal: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2D Array Operations
    int rows = 3;
    int cols = 4;
    int matrix[rows][cols] = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12}};

    // Displaying the original 2D array
    cout << "Original 2D Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Accessing Elements in 2D Array
    int element2D = matrix[1][2];
    cout << "Element at row 1, column 2 in 2D Array: " << element2D << endl;

    // Insertion in 2D Array
    matrix[1][2] = 20; // Update element at row 1, column 2
    cout << "2D Array after updating element at row 1, column 2: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deletion in 2D Array
    // Let's remove the element at row 2, column 1
    for (int i = 2; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    cols--; // Update array size
    cout << "2D Array after deleting element at row 2, column 1: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Searching in 2D Array
    int key2D = 7;
    bool found2D = false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == key2D) {
                found2D = true;
                cout << "Element " << key2D << " found at row " << i << ", column " << j << " in 2D Array." << endl;
                break;
            }
        }
        if (found2D) {
            break;
        }
    }
    if (!found2D) {
        cout << "Element " << key2D << " not found in the 2D array." << endl;
    }

    // Traversal of 2D Array
    cout << "2D Array traversal: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
