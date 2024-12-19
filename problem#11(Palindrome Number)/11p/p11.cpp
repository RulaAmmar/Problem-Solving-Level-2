

#include <iostream>
using namespace std;

enum enPalindromOrNotPalindrom
{
	Palindrom = 1, NotPalindrom
};

int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int ReverseNumber(int Number) {
	int ReverseNumber = 0;
	short Digit = 0;
	while (Number > 0) {
		Digit = Number % 10;
		ReverseNumber = ReverseNumber * 10 + Digit;
		Number /= 10;
	}
	return ReverseNumber;
}

enPalindromOrNotPalindrom CheckPalindrom(int Number) {
	if (ReverseNumber(Number) == Number)
		return Palindrom;
	else
		return NotPalindrom;
}

void PrintResult(int Number) {
	if (CheckPalindrom(Number) == Palindrom)
		cout << "\nYes,it is a palindrom number.\n";
	else
		cout << "\nNo,it is Not a palindrom number.\n";

}
int main()
{
	PrintResult(ReadPositiveNumber("Please enter a positive Number ?"));
}

