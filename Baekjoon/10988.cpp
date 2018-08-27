#include <iostream>
#include <string>
using namespace std;

int is_palindrome(string s) {
	int size = s.length();
	if (size == 1 || (size == 2 && s.at(0) == s.at(size - 1))) return 1; // 팰린드롬 가운데까지 도달했을 때
	if (s.at(0) == s.at(size - 1)) return is_palindrome(s.substr(1, size - 2)); // 같으면 계속 쪼개기
	else return 0; // 다르면 0 리턴.
}

int main() {
	string s;
	cin >> s;
	cout << is_palindrome(s);
} // 다르면 0 리턴.
