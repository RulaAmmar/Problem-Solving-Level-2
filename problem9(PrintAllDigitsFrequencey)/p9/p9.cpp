

#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number<=0);
    return Number;
}


short CountDigitFrequency(short Digit, int Number) {
    short Remainder = 0;
    short Freqcount = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        if (Remainder == Digit) {
            Freqcount++;
        }
        Number /= 10;
    }
    return Freqcount;
}


void PrintAllDigitsFrequency(int Number) {
    short Digit = 0;
    short Arr[10] = { 0 };
    short i = 0;
    while (Number>0) {
        Digit = Number % 10;//2
        if (Arr[Digit] == 0) {
          cout<< "Digit " << Digit<<" Frequncey is " << CountDigitFrequency(Digit, Number) <<" Times" << endl;
            Arr[Digit] = Digit;
        }
        Number /= 10;
        
    }
}
int main()
{
    PrintAllDigitsFrequency(ReadPositiveNumber("Please enter a positive number ?"));
}


