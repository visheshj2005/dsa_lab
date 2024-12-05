#include <iostream>
using namespace std;

int main() {
    int num, temp, digit;
    int digits[10];
    int i = 0, j;

    cout << "Enter a number: ";
    cin >> num;

    temp = num;
    while (temp != 0) {
        digit = temp % 10;
        digits[i] = digit;
        temp /= 10;
        i++;
    }

    cout << "Reversed Number: ";
    for (j = 0; j < i; j++) {
        cout << digits[j];
    }
    cout << endl;

    return 0;
}
