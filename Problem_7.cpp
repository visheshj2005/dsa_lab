#include <iostream>
using namespace std;

void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;
    inputMatrix(matrix1, rows1, cols1);

    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;
    inputMatrix(matrix2, rows2, cols2);

    cout << "\nFirst Matrix:\n";
    displayMatrix(matrix1, rows1, cols1);

    cout << "\nSecond Matrix:\n";
    displayMatrix(matrix2, rows2, cols2);

    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        cout << "\nResult of Addition:\n";
        displayMatrix(result, rows1, cols1);

        subtractMatrices(matrix1, matrix2, result, rows1, cols1);
        cout << "\nResult of Subtraction:\n";
        displayMatrix(result, rows1, cols1);
    } else {
        cout << "\nAddition and Subtraction not possible as dimensions are not the same.\n";
    }

    if (cols1 == rows2) {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        cout << "\nResult of Multiplication:\n";
        displayMatrix(result, rows1, cols2);
    } else {
        cout << "\nMultiplication not possible as the number of columns in the first matrix is not equal to the number of rows in the second matrix.\n";
    }

    return 0;
}
