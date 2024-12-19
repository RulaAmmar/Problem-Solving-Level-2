
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void PrintLetterPattren(int Number) {
	short arr[26];
	short Letter = 65;
	for (short i = 0; i < 26; i++) {
		arr[i] = Letter;
		Letter++;
	}
	for (short i = 0; i < Number; i++) {
		for (short j =0; j<=i;j++) {
			cout << (char)arr[i]<<" ";
		}
		cout << endl;
	}
}
int main()
{
	PrintLetterPattren(ReadPositiveNumber("Please enter a number ?"));
}

