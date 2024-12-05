#include <iostream>
using namespace std;

int main() {
    int num, reversedNum = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    cout << "Reversed Number: " << reversedNum << endl;

    return 0;
}
