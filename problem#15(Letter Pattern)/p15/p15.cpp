
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
	for (short i = 65; i <= 65 + Number - 1;i++) {
		for (short j = 1; j <= i-65+1;j++) {
			cout << char(i) << " ";
		}
		cout << endl;
	}
}

int main()
{
	PrintLetterPattren(ReadPositiveNumber("Please enter a positive Number?"));
}

