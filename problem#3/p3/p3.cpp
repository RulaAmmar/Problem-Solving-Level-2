

#include <iostream>
using namespace std;
enum enPerfectOrNotPerfect
{
Perfect=1,NotPerfect=2
};

short ReadPositiveNumber(string Message) {
	short Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

enPerfectOrNotPerfect CheckPerfect(short Number) {
	short Sum = 0;
	short HalfNumber = round((float)Number / 2);
	for (short i = 1; i <= HalfNumber; i++) {
		if (Number % i == 0) {
			Sum += i;
		}
	}
	if (Number == Sum) {
		return Perfect;
	}
	else {
		return NotPerfect;
	}
}

void PrintPerfetOrNotPerfect(short Number) {
	if (CheckPerfect(Number) == Perfect)
		cout<<endl << Number << " is perfect.\n";
	else
		cout <<endl<< Number << " is not perfect.\n";
}
int main()
{
	short Number = ReadPositiveNumber("Please enter a positive number ?");
	PrintPerfetOrNotPerfect(Number);
}

