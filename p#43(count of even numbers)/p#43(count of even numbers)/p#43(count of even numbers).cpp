

#include <iostream>
#include<cstdlib>
using namespace std;

enum enTypeNumber
{
	Even = 0, Odd
};

enTypeNumber CheckOddOrEven(short Number) {

	if (Number % 2 == 0)
		return Even;
	else
		return Odd;
}

short RandomNumber(int From, int To) {

	short RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrarywithRandomNumbers(short Array[100], short& arrLength) {

	cout << "Please enter a numbers of array ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {
		Array[i] = RandomNumber(1, 10);
	}
}

short CountEvenNumbersInArray(short Array[100], short arrLength) {

	short Count = 0;

	for (short i = 0; i < arrLength; i++) {
		if (CheckOddOrEven(Array[i]) == Even) {
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

	cout << "\nArray elements :\n";
	PrintArray(Array, arrLength);

	cout << "\nOdd numbers count is : " << CountEvenNumbersInArray(Array, arrLength) << endl;
}

