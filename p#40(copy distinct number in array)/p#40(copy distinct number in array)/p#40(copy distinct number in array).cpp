

#include <iostream>
using namespace std;

void FillArray(short Array[100], short &arrLength) {

	arrLength = 10;

	Array[0] = 10;
	Array[1] = 10;
	Array[2] = 10;
	Array[3] = 50;
	Array[4] = 50;
	Array[5] = 70;
	Array[6] = 70;
	Array[7] = 70;
	Array[8] = 70;
	Array[9] = 90;
}

void AddElementToArray(short Number, short Array[100], short& arrLength) {

	Array[arrLength] = Number;
	arrLength++;
}

short FindNumberPositionInArray(short NumberToSearch, short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		if (Array[i] == NumberToSearch) {
			return i;
		}
	}
	return -1;
}

bool IsNumberInArray(short NumberToCheck, short Array[100], short arrLength) {

	return FindNumberPositionInArray(NumberToCheck, Array, arrLength) != -1;
}

void CopyDistinctNumberToArray(short ArraySource[10],short ArrayDestination[10], short arr1Length,short &arr2Length) {

	for (short i = 0; i < arr1Length;i++) {
		if (!IsNumberInArray(ArraySource[i], ArrayDestination, arr2Length)) {

			AddElementToArray(ArraySource[i], ArrayDestination, arr2Length);
		}
	}

}

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

int main()
{
	short ArraySource[100],ArrayDestination[100],arr1Length,arr2Length=0;

	FillArray(ArraySource, arr1Length);
	
	cout << "Array 1 elements : \n";
	PrintArray(ArraySource, arr1Length);

	CopyDistinctNumberToArray(ArraySource, ArrayDestination, arr1Length, arr2Length);

	cout << "\nArray 2 distinct elements : \n";
	PrintArray(ArrayDestination, arr2Length);
}


