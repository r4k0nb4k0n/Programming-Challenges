#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 1 <= N <= 10,000
vector<int> v;

int main()
{
	scanf("%d",&N);
	v.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&v[i]);
	if(prev_permutation(v.begin(), v.end()))
	{
		for(int i=0;i<N;i++)
			printf("%d ",v[i]);
	}
	else
		printf("-1");
	return 0;
}