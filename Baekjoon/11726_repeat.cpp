#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int memo[1001]; // 메모이제이션 변수.

int solve(int N)
// 함수의 정의 : 2*N 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지 리턴.
{
	// 기저조건.
	if( N == 2 )
		return 2;
	if( N == 1 )
		return 1;

	int &ret = memo[N];

	if(ret != -1) // 이미 연산이 실행된 적이 있다면
		return ret; // 그 값을 리턴.

	ret = solve(N-2) + solve(N-1); // 점화식.

	return ret%10007;
}

int main(void)
{
	int n; // 1 <= n <= 1,000.
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%d",solve(n));
	return 0;
}