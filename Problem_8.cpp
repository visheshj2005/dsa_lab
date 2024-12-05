#include <iostream>
using namespace std;

// Structure to represent a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

int main() {
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int nonZeroCount = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    Element sparse[nonZeroCount];
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = sparseMatrix[i][j];
                k++;
            }
        }
    }

    cout << "Sparse Matrix Representation (row, col, value):\n";
    for (int i = 0; i < nonZeroCount; i++) {
        cout << sparse[i].row << " " << sparse[i].col << " " << sparse[i].value << endl;
    }

    return 0;
}
