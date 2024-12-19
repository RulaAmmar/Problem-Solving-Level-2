

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrarywithRandomNumbers(short Array[100], short& arrLength) {

	cout << "Please enter a numbers of array ?\n";

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

void AddElementToArray(short Number, short Array[100], short& arrLength) {

	Array[arrLength] = Number;
	arrLength++;
}

void CopyArray(short ArraySource[100],short ArrayDestination[100],short arr1Length,short &arrDestinationLength) {

	for (short i = 0; i < arr1Length; i++) {
		AddElementToArray(ArraySource[i], ArrayDestination, arrDestinationLength);
	}
}

int main()
{
 
	short Array1[100],Array2[100] ,arr1Length,arr2Length=0;

	FillArrarywithRandomNumbers(Array1, arr1Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array1, arr1Length);

	CopyArray(Array1, Array2, arr1Length, arr2Length);

	cout << "\nArray 2 elements after copy : \n";
	PrintArray(Array2, arr2Length);
}


