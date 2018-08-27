#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m.find(s) == m.end()) {
			m[s] = 1;
		}
		else {
			m[s]++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		string s;
		cin >> s;
		m[s]--;
	}
	for (auto &i : m) {
		if (i.second == 1) {
			cout << i.first;
			return 0;
		}
	}
	return 0;
}
