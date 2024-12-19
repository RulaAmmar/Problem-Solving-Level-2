

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

short CountDigitFrequency(short Digit, int Number) {
	short Remainder = 0;
	short Freqcount= 0;
	while (Number > 0) {
		Remainder = Number % 10;
		if (Remainder == Digit) {
			Freqcount++;
		}
		Number /= 10;
	}
	return Freqcount;
}

void PrintDigitFrequency(short Frequency, short Digit) {
	cout << "\nDigit " << Digit << " Frequncey is " << Frequency << " Times" << endl;
}
int main()
{
	short Digit = ReadPositiveNumber("Please enter a digit ?");
	int Number = ReadPositiveNumber("Please enter a number ?");
	PrintDigitFrequency(CountDigitFrequency(Digit,Number), Digit);
}

