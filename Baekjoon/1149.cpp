#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;
int N;
int memo[MAX][3];
int val[MAX][3];

int solve(int pos, int color) {
	if (pos == N) return 0;
	int& ret = memo[pos][color];
	if (ret != -1) return ret;
	if (color == 0) {
		ret = val[pos][color] + min(solve(pos + 1, 1), solve(pos + 1, 2));
	}
	else if (color == 1) {
		ret = val[pos][color] + min(solve(pos + 1, 0), solve(pos + 1, 2));
	}
	else {
		ret = val[pos][color] + min(solve(pos + 1, 0), solve(pos + 1, 1));
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> val[i][j];
		}
	}
	memset(memo, -1, sizeof(memo));
	int answer = min(solve(0, 0), min(solve(0, 1), solve(0, 2)));
	cout << answer;
	return 0;
}
