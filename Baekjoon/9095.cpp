#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int memo[12]; // 메모이제이션 

int solve(int n) // 1,2,3의 조합으로 나타내는 방법의 수.
{
	if(n == 0 || n < 0 ) // 기저조건.
		return 0;
	if(n == 1 )
		return 1;
	if(n == 2 )
		return 2;
	if(n == 3)
		return 4;

	int &ret = memo[n];

	if(ret != -1)
		return ret;

	ret = solve(n-1) + solve(n-2) + solve(n-3);
	
	return ret;
}

int main(void)
{
	int T;
	int n;
	scanf("%d",&T);

	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		memset(memo,-1,sizeof(memo));
		printf("%d\n",solve(n));
	}

	return 0;
}