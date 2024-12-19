
#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumber(short Array[100],short &arrLength) {

	cout << "Enter a numbers of elements ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {

		Array[i] = RandomNumber(1, 100);
	}
}

void CopyArrayWithReverseOrder(short ArraySource[100],short ArrayDestination[100],short arrLength) {

	for (short i = 0; i < arrLength;i++) {

		ArrayDestination[i] = ArraySource[arrLength-1-i];
	}

}

void PrintArray(short Array[100],short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	short ArraySource[100],ArrayDestination[100], arrLength;

	FillArrayWithRandomNumber(ArraySource, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(ArraySource, arrLength);

	CopyArrayWithReverseOrder(ArraySource, ArrayDestination, arrLength);

	cout << "Array 2 elements after copying array 1 in reversed order : \n";
	PrintArray(ArrayDestination, arrLength);
}

