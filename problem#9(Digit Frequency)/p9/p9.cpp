
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

short CountDigitFrequency(short DigitToCheck, int Number) {
	short CountFreq = 0;
	short Remainder = 0;
	while (Number > 0) {
		Remainder = Number % 10;
		if (Remainder == DigitToCheck) {
			CountFreq++;
		}
		Number /= 10;
	}
	return CountFreq;
}

void PrintAllDigitsFrequency(int Number) {
	short CountFreq = 0;
	for (short i = 0; i <= 9; i++) {
		CountFreq = CountDigitFrequency(i, Number);
		if (CountFreq > 0) {
			cout << "\nDigit " << i << " Frequency is " << CountFreq << " Times\n";
		}
	}
}

int main()
{
	PrintAllDigitsFrequency(ReadPositiveNumber("Please enter a positive number ?"));
}

