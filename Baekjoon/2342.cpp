#include <cstdio>
#include <cstring>
#include <algorithm>
#define INS_MAX 100002
#define BOX_MAX 5
using namespace std;

int memo[INS_MAX][BOX_MAX][BOX_MAX];
int instructions[INS_MAX];

int judge(int from, int to) { // from 칸에서 to 칸으로 움직였을 때 드는 힘 계산
	if (from == 0) return 2; // 중앙에서는 어디로든 2만큼 힘이 든다.
	if (from == to) return 1; // 같은 칸이라면 1만큼 힘이 든다.
	if (from % 2 == 1) { // 1 또는 3에서부터
		if (to % 2 == 0) return 3; // 2 또는 4로
		else return 4; // 1 또는 3으로
	}
	else { // 2 또는 4에서부터
		if (to % 2 == 1) return 3; // 1 또는 3으로
		else return 4; // 2 또는 4로
	}
	return 0;
}

int solve(int idx, int left, int right) {
	// 함수의 정의 : idx번째 지시사항까지, 마지막으로 left, right에 발들이 위치할 때 사용되는 최소의 힘 리턴.
	int next = instructions[idx];
	int val_left, val_right;
	
	if (next == 0) return 0; // 기저조건
	if (idx!=0 && left == right) return 1000000000; // 두 발이 같은 칸에 있을 수 없도록 매우 큰 값을 줘서 쓰이는 일이 없도록 한다.

	int& ret = memo[idx][left][right];
	if (ret != -1) return ret; // 메모이제이션

	val_left = judge(left, next); // 왼쪽 발을 움직였을 때 드는 힘 계산
	val_right = judge(right, next); // 오른쪽 발을 움직였을 때 드는 힘 계산
	
	ret = min(val_left + solve(idx + 1, next, right), val_right + solve(idx + 1, left, next));
	// 왼쪽 발을 움직였을 때랑 오른쪽 발을 움직였을 때 중 최소값을 리턴.

	return ret;
}

int main() {
	int i = 0;
	memset(memo, -1, sizeof(memo));
	while (true) {
		int input;
		scanf("%d", &input);
		instructions[i++] = input;
		if (input == 0) break;
	}
	printf("%d", solve(0, 0, 0)); // 왼쪽 발과 오른쪽 발 둘다 중앙에 있을 때부터 시작
	return 0;
}
