#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long N,K;
vector<long> v;

int main(void)
{
	scanf("%ld %ld",&N,&K);

	v.resize(N);

	for(long i=0;i<N;i++)
		scanf("%ld",&v[i]);

	nth_element(v.begin(),v.begin()+(K-1),v.end());

	printf("%ld",v[K-1]);

	return 0;
}