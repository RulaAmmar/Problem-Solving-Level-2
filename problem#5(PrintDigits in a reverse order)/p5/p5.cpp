

#include <iostream>
using namespace std;

short ReadPositiveNumber(string Message) {
    short Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintDigits(short Number) {
    cout << "\nReversed number is \n";
    short Remainder = 0;
    while (Number >0) {
        Remainder = Number % 10;
        Number /= 10;
        cout << Remainder << endl;
    }
}

int main()
{
    PrintDigits(ReadPositiveNumber("Please enter a positive number ?"));
}

