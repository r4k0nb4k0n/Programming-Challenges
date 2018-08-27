#include <cstdio>
#include <string.h>

using namespace std;

int N; // 자연수 개수.
int M; // 질문 개수.
int S,E; // Start, End.

int number[2001];
int memo[2001][2001];

bool solve(int S, int E) // S번째 수에서 E번째 수까지가 팰린드롬인지 판별해주는 함수.
{
	// 기저조건.
	if( S==E ){
		return true;
	}
	if((E-S)==1){
		if(number[S] == number[E])
			return true;
		else
			return false;
	}
	

	int &ret = memo[S][E];

	if(ret != -1)
		return ret;

	if( number[S] == number[E] )
		ret = solve(S+1,E-1);
	else
		ret = false;

	return ret;
}

int main(void)
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&number[i]);
	scanf("%d",&M);
	memset(memo,-1,sizeof(memo));
	for(int i=1;i<=M;i++)
	{
		scanf("%d %d",&S,&E);
		if(solve(S,E))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}