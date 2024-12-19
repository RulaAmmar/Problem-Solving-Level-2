

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

short ReverseNumber(short Number) {//1234
    short Digit = 0;
    short ReverseNumber = 0;
    while (Number>0) {
        Digit = Number % 10;//1
        ReverseNumber = Digit + (ReverseNumber * 10);//4321
        Number /= 10;//0
    }
    return ReverseNumber;
}

void PrintReverseNumber(short ReverseNumber) {
    cout << "The reverse number is " << ReverseNumber << endl;
}

int main()
{
    PrintReverseNumber(ReverseNumber(ReadPositiveNumber("Please enter a positive number ?")));
}


