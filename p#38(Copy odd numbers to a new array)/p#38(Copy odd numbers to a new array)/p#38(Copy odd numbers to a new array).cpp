

#include <iostream>
#include<cstdlib>
using namespace std;

enum enTypeNumber
{
	Even = 0,Odd
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

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

void AddElementToArray(short Number, short Array[100], short& arrLength) {

	Array[arrLength] = Number;
	arrLength++;
}

void CopyOddNumbersToArray(short ArraySource[100],short ArrayDestination[100],
	short arr1Length,short &arrDestinationLength) {

	for (short i = 0; i < arr1Length; i++) {

		if (CheckOddOrEven(ArraySource[i]) == Odd) {

			AddElementToArray(ArraySource[i], ArrayDestination, arrDestinationLength);
		}
		
	}

}

int main()
{
   
	srand((unsigned)time(NULL));

	short ArraySource[100], ArrayDestination[100],arr1Length,arr2Length=0;

	FillArrarywithRandomNumbers(ArraySource, arr1Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(ArraySource, arr1Length);

	CopyOddNumbersToArray(ArraySource, ArrayDestination, arr1Length, arr2Length);

	cout << "\nArray 2 Odd numbers : \n";
	PrintArray(ArrayDestination, arr2Length);
}

