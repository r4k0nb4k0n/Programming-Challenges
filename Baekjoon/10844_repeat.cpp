#include <cstdio>
#include <string.h>
#define MOD 1000000000 // 10^9.

using namespace std;

int memo[10][101]; // 메모이제이션 변수.

int solve(int X, int N)
// 함수의 정의 : 끝이 X로 시작하는 길이가 N인 계단 수가 총 몇 개인지 리턴.
{
	// 기저조건.
	if( N < 1 || ( X < 0 || X > 9 ) || ( N == 1 && X == 0) )
		return 0;
	else if( N == 1 ) // 그동안 조건을 만족해오면서 끝까지 도달했으므로
		return 1; // 리턴 1.

	int &ret = memo[X][N];
	if( ret != -1 )
		return ret;

	ret = (solve(X-1,N-1) + solve(X+1,N-1)) % MOD; // 점화식.
	return ret;
}	

int main(void)
{
	int N; // 수의 길이.
	int sum = 0; // 계단 수 합.
	memset(memo,-1,sizeof(memo));
	scanf("%d",&N);
	for(int i=0;i<10;i++)
		sum = (sum + solve(i, N))%MOD;
	printf("%d",sum);
	return 0;
}