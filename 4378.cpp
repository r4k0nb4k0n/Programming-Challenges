#include <iostream>
#include <string>
using namespace std;

string keyboard = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main() {
	string str;
	while (getline(cin, str)) {
		for (int i = 0; i < str.length(); i++) {
			char c = str.at(i);
			if (c == ' ')
				cout << c;
			else {
				cout << keyboard.at(keyboard.find(c) - 1);
			}
		}
		cout << "\n";
	}
	return 0;
}
