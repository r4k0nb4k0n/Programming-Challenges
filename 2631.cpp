#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N; // 아이들 수.
vector<int> line;
int memo[201];
int answer = 0;

int lis(int idx)
{
	// 기저조건.
	if( idx == N )
		return 0;
	
	int &ret = memo[idx];
	if( ret != -1 )
		return ret;
	for(int i=idx+1;i<N;i++)
	{
		if(line[idx] < line[i])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}

int main()
{
	scanf("%d",&N);
	memset(memo,-1,sizeof(memo));
	line.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&line[i]);
	for(int i=0;i<N;i++)
		answer = max(answer, lis(i));
	
	printf("%d",N-answer-2);
	return 0;
}