#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long card[1000001];

int main()
{
	int N; // 준규가 가지고 있는 숫자 카드의 개수.
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		scanf("%lld",&card[i]);
	}

	sort(card,card+N);

	long long answer = card[0];
	int count = 1;
	int max_count = 1;

	for(int i=1;i<N;i++)
	{
		if( card[i] == card[i-1] )
			count = count + 1;
		else
			count = 1;

		if( max_count < count )
		{
			max_count = count;
			answer = card[i];
		}
	}

	printf("%lld",answer);
	return 0;
}