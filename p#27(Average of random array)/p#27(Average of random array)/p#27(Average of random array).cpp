

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {

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

float SumArray(short Array[100], short arrLength) {

    float Sum = 0;

    for (short i = 0; i < arrLength; i++) {

        Sum += Array[i];
    }
    return Sum;
}

void PrintArray(short Array[100], short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        cout << Array[i] << " ";
    }
}

double ArrayAverage(float Sum, short arrLength) {

    return Sum / arrLength;
}

int main()
{
    srand((unsigned)time(NULL));

    short Array[100], arrLength;

    FillArrayWithRandomNumber(Array, arrLength);

    cout << "\n\nArray elements : ";
    PrintArray(Array, arrLength);

    cout << "\n\nAverage of all numbers is :";
    cout << ArrayAverage(SumArray(Array, arrLength), arrLength)<<endl;
}


