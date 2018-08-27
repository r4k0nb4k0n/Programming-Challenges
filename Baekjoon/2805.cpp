#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> // sort.

using namespace std;

long long N; // 나무의 수.
long long M; // 상근이가 집으로 가져가려고 하는 나무의 길이.
vector<long long> v;

bool judge(long long height)
{
	long long sum = 0;
	for(long long i=0;i<N;i++)
	{
		if(v[i] >= height)
			sum = sum + (v[i] - height);
	}

	if(sum >= M)
		return true;
	else
		return false;
}

long long cut(void)
{
	long long low = 0;
	long long high = v[N-1];
	long long mid;

	for(long long i=0;i<100;i++)
	{
		mid = (low + high) / 2;
		if(judge(mid))
			low = mid;
		else
			high = mid;
	}

	return low;
}

int main(void)
{
	scanf("%lld %lld",&N,&M);

	v.resize(N);

	for(long long i=0;i<N;i++)
	{
		long long temp;
		scanf("%lld",&temp);
		v[i] = temp;
	}

	sort(v.begin(),v.end()); // 오름차순 정렬.

	printf("%lld",cut());

	return 0;

}