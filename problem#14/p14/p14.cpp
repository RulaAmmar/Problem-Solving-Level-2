
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

void PrintInvertedLetterPattern(int Number) {
	for (short i = Number; i >= 1; i--) {
		for (short j = 1; j <= i;j++) {
			cout << (char)(90 - (26-i)) << " ";
		}
		cout << endl;
	}
}
int main() {
	PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
}
    

