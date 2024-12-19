

#include <iostream>
using namespace std;

void FillArray(short Array[100], short& arrLength) {

	cout << "Enter a number of elements ?\n";
	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {
		cin >> Array[i];
	}
}

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

bool IsPalindromArray(short Array[100],short arrLength) {
	
	for (short i = 0; i < arrLength / 2;i++) {

		if (Array[i] != Array[arrLength - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main()
{

	short Array[100], arrLength;

	FillArray(Array, arrLength);

	cout << "\nArray elements : \n";
	PrintArray(Array, arrLength);

	if (IsPalindromArray(Array,arrLength)) {
		cout << "\nYes array is palindrom\n";
	}
	else
		cout << "\nNo is not palindrom\n";
}


