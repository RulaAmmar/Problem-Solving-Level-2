

#include <iostream>
#include<cstdlib>
using namespace std;

enum enPrimeOrNotPrime
{
	Prime = 1, NotPrime
};

enPrimeOrNotPrime CheckPrime(short Number) {

	short HalfNumber = round(float(Number) / 2);

	for (short i = 2; i <= HalfNumber; i++) {

		if (Number % i == 0) {
			return NotPrime;
		}
	}
	return Prime;
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

void CopyPrimeNumbersToArray(short ArraySource[100],short ArrayDestination[100], short arr1Length, short& arrLengthDestination) {

	for (short i = 0; i < arr1Length; i++) {
		if (CheckPrime(ArraySource[i]) == Prime) {
			AddElementToArray(ArraySource[i], ArrayDestination, arrLengthDestination);
		}
}

}

int main()
{
 
	srand((unsigned)time(NULL));

	short ArraySource[100], ArrayDestination[100], arr1Length, arr2Length = 0;

	FillArrarywithRandomNumbers(ArraySource, arr1Length);
	
	cout << "Array 1 elements : \n";
	PrintArray(ArraySource, arr1Length);

	CopyPrimeNumbersToArray(ArraySource, ArrayDestination, arr1Length, arr2Length);

	cout << "\nArray 2 prime numbers : \n";
	PrintArray(ArrayDestination, arr2Length);
}


