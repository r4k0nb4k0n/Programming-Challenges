#include <cstdio>
#include <cstring>
#define MAX 101
long long memo[MAX];

long long solve(int n) {
	if (1 <= n && n <= 3) return 1;
	if (4 <= n && n <= 5) return 2;

	long long& ret = memo[n];
	if (ret != -1) return ret;

	ret = solve(n - 1) + solve(n - 5);
	return ret;
}

int main() {
	memset(memo, -1, sizeof(memo));
	memo[1] = memo[2] = memo[3] = 1;
	memo[4] = memo[5] = 2;
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", solve(n));
	}
	return 0;
}
