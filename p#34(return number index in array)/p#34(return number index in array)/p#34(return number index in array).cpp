
#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumber(short Array[100], short& arrLength) {

	cout << "Enter a numbers of elements ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {

		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

short FindNumberPositionInArray(short NumberToSearch, short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		if (NumberToSearch == Array[i]) {
			return i;
		}
	}
	return -1;
}

void PrintResult(short index) {
	if (index < 0) {
		cout << "\n\nThe number is not found";
	}
	else {
		cout << "\n\nThe number found at position : " << index;
		cout << "\n\nThe number found it is order : " << index + 1 << endl;
	}
		
}
int main()
{
	srand((unsigned)time(NULL));

	short Array[100], arrLength,NumberToSearch;

	FillArrayWithRandomNumber(Array, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array, arrLength);

	cout << "\nPlease enter a number to search for ?\n";
	cin >> NumberToSearch;

	cout << "\nNumber you are looking for is : " << NumberToSearch;
	PrintResult(FindNumberPositionInArray(NumberToSearch, Array, arrLength));
}


