#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int K; // 오영식이 이미 가지고 있는 랜선의 개수.
int N; // 필요한 랜선의 개수.

vector<long long> lan;

bool judge(long long idx) //
{
	int sum = 0;

	for(int i=0;i<K;i++)
	{
		sum = sum + lan[i] / idx; // 기준대로 자른 랜선의 개수 더해감.
	}

	if( sum >= N ) // 구하고자 하는 랜선의 개수보다 크거나 같으면
		return true;
	else
		return false;
}

long long cut(void) // Binary Search 
{
	long long low = 0; // low 를 0
	long long high = LLONG_MAX; // high 를 long long int 의 최대값.
	long long mid;

	for(int i=0;i<100;i++) // 100번만 해도 충분히 오차범위 안에 들어간다.
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
	scanf("%d",&K);
	scanf("%d",&N);

	lan.resize(K); // K만큼 벡터 크기 변경.

	for(int i=0;i<K;i++)
		scanf("%lld",&lan[i]); // 랜선 길이 입력.

	printf("%lld",cut()); // 정답 출력.

	return 0;
}