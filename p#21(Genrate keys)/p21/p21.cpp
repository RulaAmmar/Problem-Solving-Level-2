

#include <iostream>
#include<cstdlib>
using namespace std;

enum enCharType
{
SmallLetter=1,CapitalLetter,SpecialChar,Digit
};

int ReadPositiveNumer(string Message) {
    int Number;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number<=0);
    return Number;
}

int RandomNumber(int From,int To) {
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

void GenerateKeys(short NumberOfKeys) {

    for (short i = 1; i <= NumberOfKeys; i++) {

        cout << "Key " << "[" << i << "]" << " : ";

        cout<< GenerateKey()<<endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumer("Please enter how many keys to generate ?"));
}

