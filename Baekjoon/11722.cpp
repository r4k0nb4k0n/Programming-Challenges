#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N; // 수열의 크기.
vector<int> v;
int dynamic[1001];
int answer;

int lis(int index)
{
	// 기저조건.
	if(index == N)
		return 0;

	int &ret = dynamic[index];

	if( ret != -1 )
		return ret;

	ret = 1; 

	for(int i=index+1;i<N;i++)
	{
		if(v[index] > v[i])
			ret = max(ret, 1 + lis(i));
	}

	return ret;
}

int main()
{
	scanf("%d",&N);
	v.resize(N+1);
	memset(dynamic,-1,sizeof(dynamic));
	for(int i=0;i<N;i++)
		scanf("%d",&v[i]);
	for(int i=0;i<N;i++)
		answer = max(answer, lis(i));

	printf("%d",answer);
	return 0;
}