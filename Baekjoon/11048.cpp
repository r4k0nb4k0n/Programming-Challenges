#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int field[1001][1001];
int memo[1001][1001]; // (1,1)에서 (a,b)까지 가져올 수 있는 사탕 개수의 최대값 저장해놓음.
int N,M;

int solve(int x,int y) // (1,1)에서 (x,y)까지 가져올 수 있는 사탕 개수의 최대값
{
	// 기저조건.
	if(x < 1 || y < 1)
	{
		return 0;
	}

	int &ret = memo[x][y]; 

	if( ret != -1 )
		return ret;

	ret = field[x][y] + max(solve(x-1,y),solve(x,y-1)); // 사탕의 개수.

	return ret;
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
			scanf("%d",&field[i][j]);
	}

	memset(memo,-1,sizeof(memo));
	printf("%d",solve(N,M));

	return 0;
}