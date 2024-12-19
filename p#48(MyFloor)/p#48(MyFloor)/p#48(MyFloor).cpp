

#include <iostream>
#include<cmath>
using namespace std;

float ReadNumber() {

	float Number;

	cout << "Enter a number ?";
	cin >> Number;

	return Number;
}

int MyFloor(float Number) {
    
	int IntPart = int(Number);

	if (Number == IntPart) {
		return Number;
	}
	else if (Number > 0) {
		return IntPart;
	}
	else {
		return --IntPart;
	}
}

int main()
{
	float Number = ReadNumber();

	cout << "My MyFloor result : " << MyFloor(Number) << endl;

	cout << "C++ floor result : " << floor(Number)<<endl;
}


