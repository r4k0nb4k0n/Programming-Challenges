#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> P; // 가격 정보 담는 변수.
int memo[1001]; // 메모이제이션 변수.

int solve(int N)
// 함수의 정의 : 붕어빵의 개수 N일 때, 해빈이가 얻을 수 있는 최대 수익 리턴.
{
	// 기저조건.
	if( N == 0 )
		return 0;
	if( N == 1 )
		return P[1];

	int &ret = memo[N];
	if( ret != -1 )
		return ret;

	ret = solve(N-1) + P[1]; // 초기화.

	for(int i=2;i<=N;i++)
		ret = max(ret, solve(N-i)+P[i]); // 점화식.

	return ret;
}
int main(void)
{
	int N; // 남은 붕어빵의 개수. 1<=N<=1,000.
	scanf("%d",&N);
	P.resize(N+1);
	memset(memo,-1,sizeof(memo));
	for(int i=1;i<=N;i++)
		scanf("%d",&P[i]);
	printf("%d",solve(N));
	return 0;
}