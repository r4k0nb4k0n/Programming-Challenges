#include <cstdio>
#include <string.h>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int field[101][101];
long long memo[101][101];

int solve(int x,int y)
{

	//기저조건.

	if(x<1 || x>N || y<1 || y>N)
		return 0;
	if(x == N && y == N)
		return 1;
	if(field[x][y] == 0)
		return 0;

	long long &ret = memo[x][y];

	if( ret != -1 )
		return ret;

	int step = field[x][y];
	ret = solve(x,y+step) + solve(x+step,y);

	return ret;
}

int main(void)
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			scanf("%d",&field[i][j]);
	}

	memset(memo,-1,sizeof(memo));
	printf("%d",solve(1, 1));

	return 0;
}