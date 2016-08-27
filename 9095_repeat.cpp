#include <cstdio>
#include <string.h>

using namespace std;

int memo[12];

int solve(int N)
// 함수의 정의 : N을 1, 2, 3의 합으로 나타내는 방법의 수 출력.
{
	// 기저조건.
	if(N == 0)
		return 0;
	else if(N == 1)
		return 1;
	else if(N == 2) // 2, 1+1.
		return 2;
	else if(N == 3) // 3, 2+1, 1+2, 1+1+1.
		return 4;

	int &ret = memo[N];

	if( ret != -1 )
		return ret;

	ret = solve(N-1) + solve(N-2) + solve(N-3); // 점화식.

	return ret;

}

int main(void)
{
	int T; // 테스트 케이스의 개수.
	scanf("%d",&T);
	memset(memo,-1,sizeof(memo));
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
	return 0;
}