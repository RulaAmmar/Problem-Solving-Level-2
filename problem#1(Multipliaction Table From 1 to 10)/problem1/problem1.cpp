

#include <iostream>
using namespace std;

void PrintMultiplicationTableFrom1To10() {
	cout << "                 Multiplication Table From 1 To 10\n" << endl;
	for (int row = 1; row <= 10; row++) {
		if (row == 1) {
			for (int col = 1; col <= 10; col++) {
				cout << "\t" << col;
			}
			cout <<endl<< "_____________________________________________________________________________________"<<endl;
		}
		cout << row << "    |";
		for (int col = 1; col <= 10; col++) {
			cout <<"\t" <<row * col ;
		}
		cout << endl;
	}
}

int main()
{
	PrintMultiplicationTableFrom1To10();
}


