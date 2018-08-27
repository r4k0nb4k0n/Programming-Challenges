#include <cstdio>
#include <string.h>

using namespace std;

long long memo[1001];

long long solve(int n) // 2*n 크기의 직사각형을 1*2,2*1 타일로 채우는 방법의 수를 리턴.
{
	// 기저조건.
	if( n == 1 )
		return 1;
	if( n == 2 )
		return 2;
	if( n <= 0 )
		return 0;

	long long &ret = memo[n];

	if( ret != -1 )
		return ret;

	ret = (solve(n-1) + solve(n-2))%10007; // 점화식. 나머지 계산을 그때마다 해서 버퍼 오버플로우 방지.

	return ret;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	memset(memo,-1,sizeof(memo));
	printf("%lld",solve(n));
	return 0;
}