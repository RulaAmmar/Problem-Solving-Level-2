

#include <iostream>
using namespace std;

void PrintAllWord() {
    string Word = "";
    for (short i = 65; i <= 90; i++) {
        for (short j = 65; j <= 90; j++) {
            for (short k = 65; k <= 90; k++) {
                Word += (char)i;
                Word += (char)j;
                Word += (char)k;
                cout <<Word<< endl;
                Word = "";
            }
        }
    }
}

int main()
{
    PrintAllWord();
}

