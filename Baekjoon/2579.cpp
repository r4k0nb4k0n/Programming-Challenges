#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 300
using namespace std;

int stair[MAX], memo[MAX][3], n;

int solve(int pos, int step) {
	// 함수의 정의 : pos번째 계단까지 올라왔을 때 얻을 수 있는 총 점수의 최대값 리턴
	if (pos < 0) return 0; // 기저조건

	int& ret = memo[pos][step];
	if (ret != -1) return ret; // 메모이제이션

	ret = stair[pos]; // 밟은 계단의 수는 미리 저장한다.

	if (step == 2) { // 연속된 계단 수가 2개일 때
		ret += solve(pos - 2, 1); // 연속된 계단 수가 3개가 되지 않도록 한 계단 건너뛴다.
	}
	else { // 연속된 계단수가 1개일 때
		ret += max(solve(pos - 1, 2), solve(pos - 2, 1));
		// 한 계단 건너 뛰거나 연속으로 한 계단 더 간 것 중 최대값 리턴.
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &stair[i]);
	memset(memo, -1, sizeof(memo));
	printf("%d", solve(n - 1, 1)); // 마지막 계단을 반드시 밟아야 하므로 그냥 마지막 계단부터 시작한다.
	return 0;
}
