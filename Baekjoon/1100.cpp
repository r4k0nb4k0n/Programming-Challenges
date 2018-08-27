#include <iostream>
using namespace std;
int main() {
	char c;
	int cnt = 0;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			cin >> c;
			if ((row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1)) {
				if (c == 'F') cnt++;
			}
		}
	}
	cout << cnt;
}
