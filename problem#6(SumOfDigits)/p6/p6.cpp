
#include <iostream>
using namespace std;

short ReadPositiveNumber(string Message) {
    short Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number<=0);
    return Number;
}

short SumOfDigits(short Number) {
    short Sum = 0;
    short Remainder = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        Sum += Remainder;
        Number /= 10;
    }
    return Sum;
}

void PrintResult(short Sum) {
    cout << "\nThe sum of digits is " << Sum << endl;
}

int main()
{
    PrintResult(SumOfDigits(ReadPositiveNumber("Please enter a positive number?")));
}


