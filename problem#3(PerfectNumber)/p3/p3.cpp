

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

bool IsPerfectNumber(short Number) {
    short Sum = 0;
    for (short i = 1; i < Number; i++) {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintResult(short Number) {
    if (IsPerfectNumber(Number))
        cout << "\n" << Number << " Is perfect.\n";
    else
        cout << "\n" << Number << " Is not perfect.\n";
}
int main()
{
    PrintResult(ReadPositiveNumber("Please enter a positive number?"));
}

