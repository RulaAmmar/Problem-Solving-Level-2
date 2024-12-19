

#include <iostream>
using namespace std;

int ReadNumber() {

	int Number;

	cout << "\nPlease enter a number ?";

	cin >> Number;

	return Number;
}

void AddElementToArray(int Number, int Array[100], int &arrLength) {

	Array[arrLength] = Number;
	arrLength++;
}

void InputUserNumberInArray(int Array[100], int &arrLength) {

	bool AddMore=false;

	do {
		AddElementToArray(ReadNumber(), Array, arrLength);
		cout << "\nDo you want to add more numbers ?[0]:No,[1]:Yes?";
		cin >> AddMore;
	} while (AddMore);
}


void PrintArray(int Array[100], short arrLength) {

	for (short i = 0; i < arrLength; i++) {
		cout << Array[i] << " ";
	}
}

int main()
{
 
	int Array[100];
	int arrLength = 0;

	InputUserNumberInArray(Array, arrLength);

	cout << "\n\nArray length: " << arrLength<<endl;

	cout << "Array elements : ";
	PrintArray(Array, arrLength);
}


