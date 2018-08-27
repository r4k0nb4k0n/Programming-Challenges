#include <cstdio>
#include <string.h>

using namespace std;

int memo[91];

int solve(int N) // N자리 이친수의 개수를 리턴.
{
	//기저 조건.
	if( N == 1 || N == 2)
		return 1;
	if( N <= 0 )
		return 0;

	int &ret = memo[N];

	if( ret != -1 )
		return ret;
	
	ret = solve(N-1) + solve(N-2); // 점화식. 피보나치 점화식과 같다.

	return ret;
}

int main(void)
{
	int N;
	scanf("%d",&N);
	memset(memo,-1,sizeof(memo));
	printf("%d",solve(N));
	return 0;
}