
#include <iostream>
#include<cmath>
using namespace std;

enum enPositiveOrNegative
{
	Positive = 1, Negative
};

enPositiveOrNegative CheckPositiveOrNegative(short Number) {

	if (Number >= 0) {
		return Positive;
	}
	else
		return Negative;
}

float ReadNumber() {

	float Number;

	cout << "Enter a number ?";
	cin >> Number;

	return Number;
}

float GetFractionPart(float Number) {

	return Number - int(Number);
}

int MyRound(float Number) {

	int IntPart = int(Number);

	float FractionPart = GetFractionPart(Number);//0.7

	if (abs(FractionPart)>= 0.5) {

		if (CheckPositiveOrNegative(Number) == Positive) {
			return ++IntPart;
		}
		else
			return --IntPart;
	}
	else {
		return IntPart;
	}
		

}
int main()
{
	float Number = ReadNumber();

	cout << "My Round result : " << MyRound(Number)<<endl;

	cout << "C++ Round result : " << MyRound(Number) << endl;

}


