

#include <iostream>
#include<cmath>
using namespace std;

int ReadNumber() {

	int Number;

	cout << "Enter a number ?";
	cin >> Number;

	return Number;
}

float MySqrt(int Number) {

	return pow(Number, .5);

}

int main()
{
int Number = ReadNumber();

cout << "My MySqrt result : " << MySqrt(Number)<<endl;

cout << "C++ sqrt result: " << sqrt(Number) << endl;
}


