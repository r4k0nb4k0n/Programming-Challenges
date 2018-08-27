#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 1003
#define mval INT_MIN/2;
using namespace std;

int n, m;
int v[MAX][MAX];
int memo[MAX][MAX][2];
int mv_x[3] = { 0, 0, 1 }; // 좌, 우, 하
int mv_y[3] = { -1, 1, 0 }; // 좌, 우, 하


bool within_range(int x, int y) { // 해당 위치가 탐사 범위를 벗어나지 않는지 판단.
	if (1 <= x&&x <= n && 1 <= y&&y <= m) return true;
	else return false;
}

int solve(int x, int y, int d) { // 함수의 정의 : (1,1)에서 (x, y)까지 왔을 때 탐사한 지역들의 가치의 최대 합 리턴.
	if (!within_range(x, y)) return mval; // 해당 위치가 탐사 범위를 벗어나면 최소값 먹이기.
	if (x == n && y == m) return v[x][y]; // (n, m) 도착 시 해당 위치 탐사가치 리턴.

	int& ret = memo[x][y][d]; // 메모이제이션
	if (ret != -1) return ret; // 이미 연산된 위치는 다시 연산할 필요가 없다.

	ret = mval;

	// 좌우
	// 입력받은 방향으로 다음 위치 계산.
	int next_x = x + mv_x[d];
	int next_y = y + mv_y[d];

	if (within_range(next_x, next_y)) // 다음 위치가 탐사 범위를 벗어나지 않는다면
		ret = v[x][y] + solve(next_x, next_y, d); // 다음 위치로 갔을 때 최대값 계산.

	// 하
	// 아래로 간 방향으로 다음 위치 계산.
	next_x = x + mv_x[2];
	next_y = y + mv_y[2];

	// (좌 또는 우로 갔을 때)와 (아래로 가고 난 후 좌 또는 우로 갔을 때) 중 최대값 리턴.
	ret = max(ret, v[x][y] + max(solve(next_x, next_y, 0), solve(next_x, next_y, 1)));

	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j]; // 탐사 가치 입력
			memo[i][j][0] = memo[i][j][1] = -1; // 메모이제이션 초기화
		}
	}
	cout << max(solve(1, 1, 0), solve(1, 1, 1)); // (1, 1)에서 출발 방향 우, 하 중 최대값 출력.
	return 0;
}
