

#include <iostream>
#include<cstdlib>
using namespace std;

enum enCharType
{
    SmallLetter = 1, CapitalLetter, SpecialChar, Digit
};

int ReadPositiveNumer(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enCharType CharType) {
    switch (CharType) {

    case SmallLetter:
        return char(RandomNumber(97, 122));

    case CapitalLetter:
        return char(RandomNumber(65, 90));

    case SpecialChar:
        return char(RandomNumber(33, 47));

    case Digit:
        return char(RandomNumber(48, 57));
    }
}

string GenerateWord(enCharType CharType, short Length) {

    string Word = "";

    for (short i = 1; i <= Length; i++) {

        Word += GetRandomCharacter(CapitalLetter);
    }

    return Word;
}

string GenerateKey() {

    string Key = "";

    for (short i = 1; i <= 4; i++) {

        Key += GenerateWord(CapitalLetter, 4);

        if (i < 4) {
            Key += '-';
        }
    }

    return Key;

}

void FillArrayWithKeys(string Array[100],short &arrLength) {

    cout << "Enter a number of elements : \n";

    cin >> arrLength;

    for (short i = 0; i < arrLength; i++) {
        Array[i] = GenerateKey();
    }
}

void PrintArray(string Array[100], short arrLength) {
    for (short i = 0; i < arrLength; i++) {
        cout << "Array [" << i << "] : ";
        cout << Array[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    string Keys[100];
    short arrLength;

    FillArrayWithKeys(Keys, arrLength);

    cout << "\nArray elements: \n\n";
    PrintArray(Keys, arrLength);
}

