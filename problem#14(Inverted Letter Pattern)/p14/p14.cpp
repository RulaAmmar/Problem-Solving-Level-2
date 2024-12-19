
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

void PrintLetterPattern(int Number) {
    for (short i = 65 + Number - 1; i >= 65; i--) {
        for (short j = 1;j<=Number-(65+Number-1-i);j++) {
            cout << (char)i << " ";
        }
      
        cout << endl;
    }
}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
}


