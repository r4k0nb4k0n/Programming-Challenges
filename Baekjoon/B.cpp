#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N; // 수열 길이.
vector<int> s;
vector<vector<long long> > memo;

long long solve(int from, int to)
{
	// 기저조건
	if( from == to )
		return s[from-1];

	long long &ret = memo[from][to];
	if( ret != -1 )
		return ret;

	ret = s[to-1] * solve(from, to-1);

	return ret%1000000007;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		s.clear();
		s.resize(N);
		memo.clear();
		memo.resize(N+1);
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N+1;j++)
				memo[i].push_back(-1);
			scanf("%d",&s[i]);
		}
		long long answer = s[0];
		for(int i=1;i<=N;i++)
		{
			answer = max(answer, solve(i,N));
		}
		printf("%lld\n",answer);
	}
	return 0;
}