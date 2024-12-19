

#include <iostream>
using namespace std;
#include<string>

string ReadText() {
	string Text;
	cout << "Please enter text ?" << endl;
	getline( cin ,Text);
	return Text;
}

string EncryptText(string Text,short EncryptionKey) {


	for (short i = 0; i < Text.length(); i++) {

		Text[i] = char(Text[i] + EncryptionKey);

	}

	return Text;
}

string DecryptText(string Text,short EncryptionKey) {

	for (short i = 0; i < Text.length(); i++) {

		Text[i] = (char)(Text[i] - EncryptionKey);
	}

	return Text;
}

int main()
{
	const short EncryptionKey = 2;

	string Text = ReadText();

	string EncryptedText = EncryptText(Text,EncryptionKey);

	cout << "\nText before encryption : " << Text << endl;
	
	cout << "Text after encryption : " << EncryptedText<< endl;

	cout << "Text after decryption : " << DecryptText(EncryptedText,EncryptionKey) << endl;
}

