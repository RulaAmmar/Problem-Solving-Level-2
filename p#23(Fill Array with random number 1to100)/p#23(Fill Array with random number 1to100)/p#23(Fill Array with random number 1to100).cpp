

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrarywithRandomNumbers(short Array[100],short &arrLength) {

	cout << "Please enter a numbers of array ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(short Array[100],short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}

}
int main()
{
	srand((unsigned)time(NULL));

	short Array[100],arrLength;

	FillArrarywithRandomNumbers(Array, arrLength);

	cout << "\nArray elements : ";
	PrintArray(Array, arrLength);

}

