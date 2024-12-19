

#include <iostream>
using namespace std;

short ReadPositiveNumber(string Message) {
	short Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

bool IsPerfectNumber(short Number) {
	short Sum = 0;
	if (Number == 1)
		return 0;
	else {
		for (short i = 1; i < Number; i++) {
			if (Number % i == 0) {
				Sum += i;
			}
		}
		return Sum == Number;
	}
}


void PrintPerfectNumberFrom1toN(short Number) {
	cout << "\nPerfect number from " << 1 << " to " << Number << endl;
	for (short i = 1; i <= Number; i++) {
		if (IsPerfectNumber(i)) {
			cout << i << endl;
		}
	}
}
int main()
{
	PrintPerfectNumberFrom1toN(ReadPositiveNumber("Please enter a positive number ?"));
}

