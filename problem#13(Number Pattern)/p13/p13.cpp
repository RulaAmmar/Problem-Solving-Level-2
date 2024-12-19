

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

void PrintPattren(int Number) {
	cout << endl;
	for (short i = 1; i <= Number; i++) {
		{
			for (short j = 1; j <= i; j++) {
				cout << i << " ";
}
		}
		cout << endl;
}
}

int main()
{
	PrintPattren(ReadPositiveNumber("Please enter a positive number ?"));
}

