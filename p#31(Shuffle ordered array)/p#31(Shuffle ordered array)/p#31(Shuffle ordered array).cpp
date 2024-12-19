

#include <iostream>
#include<cstdlib>
using namespace std;

int ReadPositiveNumber(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
      
    } while (Number<=0);

    return Number;
}

int RandomNumber(int From, int To) {

    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;

}

void FillArrayWith1ToN(short Array[100],short arrLength) {

    for (short i = 0; i < arrLength;i++) {

        Array[i] = i + 1;
    }
}

void Swap(short &Number1,short &Number2) {

    short Temp = 0;

    Temp = Number1;

    Number1 = Number2;

    Number2 = Temp;
}

void ShuffleArray(short Array[100], short arrLength) {

    for (short i = 0; i <arrLength; i++) {

        Swap(Array[RandomNumber(1,arrLength)-1],Array[RandomNumber(1,arrLength)-1]);
    }
}


void PrintArray(short Array[100],short arrLength) {

    for (short i = 0; i < arrLength; i++) {

        cout << Array[i] << " ";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    short Array[100], arrLength;

    arrLength = ReadPositiveNumber("Enter a number of elements ?");

    FillArrayWith1ToN(Array, arrLength);

    cout << "\nArray elements before shuffle : \n";
    PrintArray(Array, arrLength);

    ShuffleArray(Array, arrLength);

    cout << "\nArray elements After shuffle : \n";
    PrintArray(Array, arrLength);
}

