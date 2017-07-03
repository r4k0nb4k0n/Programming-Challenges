#include <iostream>
using namespace std;
int A, B, V;
int main() {
	cin >> A >> B >> V;
	int days = 0;
	int sum = 0;
	while (++days) {
		sum += A;
		if (sum >= V) break;
		sum -= B;
	}
	cout << days;
	return 0;
}
