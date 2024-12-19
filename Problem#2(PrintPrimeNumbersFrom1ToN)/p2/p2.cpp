
#include <iostream>
using namespace std;
#include<cmath>
enum enPrimeNotPrime
{
prime=1,NotPrime=2
};
enPrimeNotPrime CheckPrime(short Number) {
    if (Number == 1)
        return NotPrime;
    else if (Number == 2)
        return prime;
    else {
        short HalfNumber = 0;
        HalfNumber = round((float)Number / 2);
        for (short i = 2; i <= HalfNumber; i++) {
            if (Number % i == 0) {
                return NotPrime;
            }
        }
        return prime;
    }
   
}

short ReadPositiveNumber(string Message) {
    short Number;
    do {
        cout << Message << "\n";
        cin >> Number;
    } while (Number<=0);
    return Number;
}

void PrintAllPrimeNumberFrom1ToN(short Number) {


    cout << "\n";
    cout<< "Prime Number from "<<1<<" To " << Number;
    cout << " are :" << endl;

    for (short i = 1; i <= Number; i++) {
        if (CheckPrime(i) == prime) {
            cout << i << endl;
        }
    }
}
int main()
{
    short Number=ReadPositiveNumber("Please enter a positive number ?");
    PrintAllPrimeNumberFrom1ToN(Number);
}

