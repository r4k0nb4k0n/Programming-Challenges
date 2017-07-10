#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 300
using namespace std;

int stair[MAX], memo[MAX][3], n;

int solve(int pos, int step) {
	if (pos < 0) return 0;

	int& ret = memo[pos][step];
	if (ret != -1) return ret;

	ret = stair[pos];

	if (step == 2) {
		ret += solve(pos - 2, 1);
	}
	else {
		ret += max(solve(pos - 1, 2), solve(pos - 2, 1));
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &stair[i]);
	memset(memo, -1, sizeof(memo));
	printf("%d", solve(n - 1, 1)); // 마지막 계단을 반드시 밟아야 하므로 그냥 여기서부터 시작한다.
	return 0;
}
