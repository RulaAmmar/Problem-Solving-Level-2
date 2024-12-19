

#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number<=0);
	return Number;
}

int ReverseNumber(int MainNumber) {
	int ReverseNumber = 0;
	short Digit = 0;
	while (MainNumber > 0) {
		Digit = MainNumber % 10;
		ReverseNumber = ReverseNumber * 10 + Digit;
		MainNumber /= 10;
	}
	return ReverseNumber;
}

void PrintDigitsInOrder(int Number) {
	short Digit = 0;
	while (Number > 0) {
		Digit = Number % 10;
		cout << Digit << endl;
		Number /= 10;
}
}


int main()
{
	PrintDigitsInOrder(ReverseNumber(ReadPositiveNumber("Please enter a number ?")));
}
