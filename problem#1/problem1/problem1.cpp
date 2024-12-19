

#include <iostream>
using namespace std;
void PrintTableHeader() {
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    for (short i = 1; i <= 10; i++) {
        cout << "\t" << i;
    }
    cout << "\n_____________________________________________________________________________________\n";
}
string ColumSperator(short i) {
    if (i < 10)
        return "   |";
    else
        return "  |";
}
void PrintMultiplicationTable() {
    PrintTableHeader();
    for (short row = 1; row <= 10; row++) {
        cout << row << ColumSperator(row) << "\t";
        for (short col = 1;col<= 10; col++) {
            cout << row * col<< "\t";
        }
        cout << endl;
    }
}
int main()
{
    PrintMultiplicationTable();
}

