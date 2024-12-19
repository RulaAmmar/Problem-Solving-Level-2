

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

    for (short i = 0; i < arrLength; i++) {
        Array[i] = RandomNumber(1, 100);
    }
}


void PrintArray(short Array[100],short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        cout << Array[i] << " ";
    }
    cout << endl;
}

short MaxNumberInArray(short Array[100],short arrLength) {

    short Max = 0;

    for (short i = 0; i < arrLength; i++) {

        if (Max < Array[i])
        {
            Max = Array[i];
        }
    }
    return Max;
}

int main()
{

    short Array[100], arrLength;

    srand((unsigned)time(NULL));

    FillArrayWithRandomNumber(Array, arrLength);

    cout << "\nArray elements : ";
    PrintArray(Array,arrLength);

    cout << "\nMax number is : ";
    cout<< MaxNumberInArray(Array, arrLength) << endl;
}


