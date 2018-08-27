#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

string s1, s2;
int memo[MAX][MAX];

int solve(int i, int j) { // 함수의 정의 : 두 문자열의 LCS의 길이 리턴.
	if (i < 0 || j < 0) return 0; // 기저조건

	// 메모이제이션
	int& ret = memo[i][j];
	if (ret != -1) return ret;

	// 점화식
	if (i == 0 || j == 0) ret = 0;
	else if (s1.at(i-1) == s2.at(j-1)) ret = solve(i - 1, j - 1) + 1;
	else ret = max(solve(i - 1, j), solve(i, j - 1));

	return ret;
}

int main() {
	cin >> s1 >> s2;
	memset(memo, -1, sizeof(memo));
	cout << solve(s1.length(), s2.length());
	return 0;
}
