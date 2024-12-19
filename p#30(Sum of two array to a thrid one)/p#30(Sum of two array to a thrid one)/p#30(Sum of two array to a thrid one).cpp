
#include <iostream>
#include<cstdlib>
using namespace std;

int ReadPositiveNumer(string Message) {
	int Number;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumber(short Array[100], short &arrLength) {

	for (short i = 0; i < arrLength; i++) {

		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(short Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {

		cout << Array[i] << " ";
	}
}


void SumOfTwoArray(short Array1[100],short Array2[100],short Array3[100],short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		Array3[i] = Array1[i] + Array2[i];
	}

}

int main()
{
	srand((unsigned)time(NULL));

	short Array1[100], Array2[100],Array3[100], arrLength;

	arrLength = ReadPositiveNumer("Enter a number of element ?\n");

	FillArrayWithRandomNumber(Array1, arrLength);

	FillArrayWithRandomNumber(Array2, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array1, arrLength);

	cout << "\n\nArray 2 elements : \n";
	PrintArray(Array2, arrLength);

	SumOfTwoArray(Array1, Array2, Array3, arrLength);

	cout << "\n\nSum of array1 and array2 elements : \n";
	PrintArray(Array3, arrLength);

	cout << endl;
}


