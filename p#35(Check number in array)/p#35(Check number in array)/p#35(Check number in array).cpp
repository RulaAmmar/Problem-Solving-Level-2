

#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNumber(short Array[100], short &arrLength) {

	cout << "Enter a numbers of elements ?\n";

	cin >> arrLength;

	for (short i = 0; i < arrLength; i++) {
		Array[i] = RandomNumber(1, 100);
	}
}

short FindNumberPositionInArray(short NumberToSearch,short Array[100],short arrLength) {

	for (short i = 0; i < arrLength;i++) {
		if (Array[i] == NumberToSearch) {
			return i;
		}
	}
	return -1;
}

bool IsNumberInArray(short NumberToCheck,short Array[100],short arrLength) {

	return FindNumberPositionInArray(NumberToCheck, Array, arrLength) != -1;
}

void PrintResult(bool Result) {
	 
	if (Result){
		cout << "\nYes the number is found :-)\n";
	}
	else
		cout << "\nNo the number is not found :-(\n";
	
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

	short Array[100], arrLength,NumberToSearch;

	FillArrayWithRandomNumber(Array, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array, arrLength);

	cout << "\nPlease enter a number to search for ?\n";
	cin >> NumberToSearch;

	cout << "\nNumber you are looking for is : " << NumberToSearch;
	PrintResult(IsNumberInArray(NumberToSearch,Array,arrLength));
}


