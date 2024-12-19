

#include <iostream>
using namespace std;

string ReadPassword() {
	string Password;
	cout << "Please enter a 3-Letter password (all capital)?" << endl;
	cin >> Password;
	return Password;
}

bool GuessPassword(string OriginalPassword) {

	short TriesCount = 0;

	string GuessPassword = "";

	for (short i = 65; i <= 90; i++) {
		for (short j = 65; j <= 90; j++) {
			for (short k = 65; k <= 90; k++) {

				GuessPassword = GuessPassword +(char)i + (char)j + (char)k;
				
				TriesCount++;

				cout << "Trial " << "[" << TriesCount << "]" << " : " << GuessPassword;

				cout << endl;

				if (GuessPassword == OriginalPassword) {
					cout << "\nPassword is " << OriginalPassword << endl;
					cout << "Found after " << TriesCount << " Trials" << endl;
					return true;
				}

				GuessPassword = "";
			}
		}
	}
	return false;
}
int main()
{
	GuessPassword(ReadPassword());
}


