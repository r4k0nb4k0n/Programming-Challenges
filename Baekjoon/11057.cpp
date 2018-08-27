#include <cstdio>
#include <cstring>
#define MOD 10007

int N; // 길이 1 <= N <= 1001인 자연수.
int memo[10][1001];
int solve(int X,int n) // 함수의 정의 : n자리일 때 오르막 수 개수 리턴.
{
	// 기저조건.
	if(X<0 || n<0)
		return 0;
    if(n==1 && !(X<0)) // 그동안 조건 만족하면서 끝까지 도달
		return 1;

	int &ret = memo[X][n]; // 주소 일치

	if( ret != 0 )
		return ret;

	for(int i=0;i<=X;i++)
		ret = ret + solve(i,n-1)%MOD; // 점화식

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
