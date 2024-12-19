
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

    for (short i = 0; i < arrLength;i++) {

        Array[i] = RandomNumber(1, 100);
    }
}


int SumOfNumbersInArray(short Array[100], short arrLength) {

    int Sum = 0;

    for (short i = 0; i < arrLength; i++) {

        Sum += Array[i];
    }
    return Sum;
}

void PrintArray(short Array[100],short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        cout << Array[i] << " ";
    }
    cout << endl;
}


int main()
{
 
    srand((unsigned)time(NULL));

    short Array[100], arrLength;

    FillArrayWithRandomNumber(Array, arrLength);

    cout << "Array elemnts : ";
    PrintArray(Array, arrLength);

    cout << "\nSum of all number is : ";
    cout << SumOfNumbersInArray(Array, arrLength)<<endl;
}


