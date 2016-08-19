#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N; // 한 더미의 카드의 개수를 나타내는 자연수. 최대 2,000.
vector<int> left; // 왼쪽 더미.
vector<int> right; // 오른쪽 더미.
int memo[2001][2001];

int solve(int L, int R) // 함수의 정의 : 최종 점수의 최대값 출력.
{
	// 기저 조건.
	if( L == N || R == N )
		return 0; // 규칙 3.

	int &ret = memo[L][R];
	if( ret != -1 )
		return ret;

	ret = max(solve(L+1,R), solve(L+1,R+1)); // 규칙 1.

	if(left[L] > right[R])
		ret = max(ret, solve(L,R+1)+right[R]); // 규칙 2.

	return ret;
}

int main()
{
	scanf("%d",&N);
	left.resize(N);
	right.resize(N);
	memset(memo,-1,sizeof(memo));
	for(int i=0;i<N;i++)
		scanf("%d",&left[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&right[i]);
	printf("%d",solve(0,0));
}