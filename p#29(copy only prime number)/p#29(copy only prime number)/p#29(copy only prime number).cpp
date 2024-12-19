

#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

enum enPrimeOrNotPrime
{
Prime=1,NotPrime
};

int RandomNumber(int From,int To) {

	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumber(short Array[100],short &arrLength) {
	
	cout << "Please enter a number of elements ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {

		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {

		cout << Array[i] << " ";
	}
}

enPrimeOrNotPrime CheckPrime(short Number) {

	short HalfNumber = round(float(Number) / 2);

	for (short i = 2; i <= HalfNumber; i++) {

		if (Number % i == 0) {
			return NotPrime;
		}
	}
	return Prime;
}

void CopyOnlyPrimeNumber(short ArraySource[100],short ArrayDestination[100],short arrLength,short &arr2Length) {

	short Counter = 0;

	for (short i = 0; i < arrLength; i++) {

		if (CheckPrime(ArraySource[i]) == Prime) {

			ArrayDestination[Counter] = ArraySource[i];

			Counter++;
		}
	}
	arr2Length = Counter;
}


int main()
{
  
	srand((unsigned)time(NULL));

	short Array[100],ArrayDestination[100], arrLength,arr2Length;

	FillArrayWithRandomNumber(Array,arrLength);

	CopyOnlyPrimeNumber(Array,ArrayDestination,arrLength,arr2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array, arrLength);

	cout << "\nPrimes number in array 2 : \n";
	PrintArray(ArrayDestination, arr2Length);

	
}


