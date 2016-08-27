#include <cstdio>
#include <string.h>
#define MOD 10007

using namespace std;

int N; // 길이 1 <= N <= 1001인 자연수.
int memo[10][1001];
int solve(int X,int n) // n자리일 때 오름차 수 개수 리턴.
{
	// 기저조건.
	if( n==1 && !(X<0) )
		return 1;
	if(X<0 || n<0)
		return 0;

	int &ret = memo[X][n];

	if( ret != 0 )
		return ret;

	for(int i=0;i<=X;i++)
	{
		ret = ret + solve(i,n-1)%MOD;
	}

	return ret%MOD;

}	

int main(void)
{
	scanf("%d",&N);
	int sum = 0;
	memset(memo,0,sizeof(memo));
	for(int i=0;i<10;i++)
		sum = sum + solve(i,N)%MOD;
	printf("%d",sum%MOD);
	return 0;
}