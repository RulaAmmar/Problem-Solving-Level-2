

#include <iostream>
#include<cmath>
using namespace std;

int ReadNumber() {

    int Number;

    cout << "Enter a number ?";
    cin >> Number;

    return Number;
}

int Myabs(int Number) {
    if (Number > 0) {
        return Number;
    }
    else
        return -1*Number;
}


int main()
{
    int Number = ReadNumber();

    cout << "My abs result : " << Myabs(Number);

    cout << "\nC++ abs result : " << abs(Number);
}

