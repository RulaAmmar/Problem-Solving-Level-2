

#include <iostream>
#include<cmath>
using namespace std;

float ReadNumber() {

	float Number;

	cout << "Enter a number ?";
	cin >> Number;

	return Number;
}

float GetFractionPart(float Number) {

	return Number - int(Number);
}

int MyCeil(float Number) {
	
	int IntPart = int(Number);

	if (abs(GetFractionPart(Number)) > 0) {
		if (Number > 0) {
			return ++IntPart;
		}
		else
		{
			return IntPart;
		}
	}
	else {
		return IntPart;
	}
	
}
int main()
{
	float Number = ReadNumber();
  
	cout << "My MyCeil Result : " << MyCeil(Number)<<endl;

	cout << "C++ ceil result : " << ceil(Number) << endl;
}

