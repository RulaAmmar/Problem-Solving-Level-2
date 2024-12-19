

#include <iostream>
#include<cstdlib>
using namespace std;

enum enPositiveOrNegative
{
	Positive = 1, Negative
};

enPositiveOrNegative CheckPositiveOrNegative(short Number) {

	if (Number >= 0) {
		return Positive;
	}
	else
		return Negative;
}
short RandomNumber(int From, int To) {

	short RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrarywithRandomNumbers(short Array[100], short& arrLength) {

	cout << "Please enter a numbers of array ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {
		Array[i] = RandomNumber(-100, 100);
	}
}

short CountPositiveNumbersInArray(short Array[100], short arrLength) {

	short Count = 0;

	for (short i = 0; i < arrLength; i++) {

		if (CheckPositiveOrNegative(Array[i]) == Positive) {

			Count++;
		}
	}
	return Count;
}

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	short Array[100], arrLength;

	FillArrarywithRandomNumbers(Array, arrLength);

	cout << "\nArray elements : \n";
	PrintArray(Array, arrLength);

	cout << "\nPositive number count is: " << CountPositiveNumbersInArray(Array, arrLength) << endl;
}


