#include <iostream>
using namespace std;
int main() {
	int n, d;
	cin >> n;
	for (d = 2; d*d <= n; d++) { // 2에서 root(N)까지 약수 존재여부 검사
		if (n%d == 0) break; // 1을 제외한 가장 작은 약수 찾기
	}
	if (d*d > n) d = n; // n이 소수일 때, 약수가 1과 자기 자신밖에 없다.
	cout << n - (n/d); // 결과 출력
	return 0;
}
