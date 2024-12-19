

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


void PrintInvertedNumberPattren(int Number) {
	for (short i = Number; i >= 1; i--) {
		for (short j = 1; j <= i;j++) {
			cout << i << " ";
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedNumberPattren(ReadPositiveNumber("Please enter a positive number ?"));
}


