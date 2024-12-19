

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From,int To) {

    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

void FillArrayWithRandomNumber(short Array[100],short &arrLength) {

    cout << "Please enter a number of elements ?\n";

    cin >> arrLength;

    for (short i = 0; i < arrLength;i++) {
        Array[i] = RandomNumber(1, 100);
    }

}

void PrintArray(short Array[100],short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        cout << Array[i] << " ";

    }
    cout << endl;
}

short MinNumberInArray(short Array[100],short arrLength) {

    short Min = Array[0];

    for (short i = 1; i < arrLength; i++) {

        if (Array[i] < Min) {
            Min = Array[i];
        }
    }
    return Min;
}
int main()
{
    srand((unsigned)time(NULL));

    short Array[100], arrlength;

    FillArrayWithRandomNumber(Array, arrlength);

    cout << "\nArray elements : ";
    PrintArray(Array, arrlength);

    cout << "\nMin number is : ";
    cout << MinNumberInArray(Array, arrlength) << endl;
}


