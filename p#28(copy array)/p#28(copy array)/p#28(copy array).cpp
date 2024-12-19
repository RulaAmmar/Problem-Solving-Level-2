

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {

    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}

void FillArrayWithRandomNumber(short Array[100], short& arrLength) {

    cout << "Please enter a number of elements ?\n";

    cin >> arrLength;

    for (short i = 0; i < arrLength; i++) {

        Array[i] = RandomNumber(1, 100);
    }
}

void PrintArray(short Array[100], short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        cout << Array[i] << " ";
    }
}

void CopyArray(short ArraySource[100],short ArrayDestination[100],short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        ArrayDestination[i] = ArraySource[i];
    }
}


int main()
{
  
    srand((unsigned)time(NULL));

    short ArraySource[100], arrLength,ArrayDestination[100];

    FillArrayWithRandomNumber(ArraySource, arrLength);

    CopyArray(ArraySource, ArrayDestination, arrLength);

    cout << "\nArray 1 elements : \n";
    PrintArray(ArraySource, arrLength);

    cout << "\n\nArray 2 elements after copy : \n";
    PrintArray(ArrayDestination, arrLength);
    cout << endl;
}

