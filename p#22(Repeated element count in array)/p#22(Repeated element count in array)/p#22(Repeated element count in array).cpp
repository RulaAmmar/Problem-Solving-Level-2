

#include <iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number;
	do {
		cout << Message;
		cin >> Number;
	} while (Number<=0);
	return Number;
}

void ReadArray(short Array[100],short &arrLength) {

	arrLength=ReadPositiveNumber("Please enter number of elements : \n");

	cout << "\nEnter array elements :\n";

	for (short i = 0; i < arrLength; i++) {

		cout << "Element [" << i + 1 << "] : ";

		cin >> Array[i];
	}
	
}

short TimesRepeated(short NumberToCheck, short Array[100],short arrLength) {
	short CountFreq = 0;

	for (short i = 0; i < arrLength; i++) {

		if (Array[i] == NumberToCheck) {
			CountFreq++;
		}
	}
	return CountFreq;
}

void PrintArray(short Array[100],short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		
		cout << Array[i] << " ";
	}
	cout << endl<<endl;
}

int main()
{
	short Array[100],arrLength;

	ReadArray(Array, arrLength);

	short NumberToCheck = ReadPositiveNumber("\nEnter the number you want to check : ");

	cout << "\nOriginal array : ";
	PrintArray(Array,arrLength);
	
	cout <<"Number " << NumberToCheck 
		<<" is repeated " << TimesRepeated(NumberToCheck, Array, arrLength) 
		<< " time(s)" << endl;
}