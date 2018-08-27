#include <cstdio>
#include <string.h>
#define MOD 1000000000

using namespace std;

int N; // 길이 1 <= N <= 100인 자연수.
int memo[10][101];
int solve(int X,int n) // n자리일 때 계단 수 개수 리턴.
{
	// 기저조건.
	if( n<1 || (X<0 || X>9) || (n==1 && X==0) )
		return 0;
	else if( n==1 )
		return 1;

	int &ret = memo[X][n];

	if( ret != -1 )
		return ret;

	ret = (solve(X-1,n-1) + solve(X+1,n-1))%MOD;

	return ret;

}	

int main(void)
{
	scanf("%d",&N);
	int sum = 0;
	memset(memo,-1,sizeof(memo));
	for(int i=0;i<10;i++)
		sum = (sum + solve(i,N)%MOD)%MOD;
	printf("%d",sum);
	return 0;
}