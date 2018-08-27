#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long N; // 상근이가 가지고 있는 숫자 카드의 개수.
vector<long long> n;
long M;
vector<long long> m;

int BinarySearch(long long obj)
{
	int low = 0;
	int high = N-1;
	int cnt = 0;
	int mid = (low + high) / 2;
	
	while(low <= high)
	{
		mid = (low + high) / 2;

		if( obj == n[mid] )
		{
			for(int i=low;i<=high;i++)
			{
				if(n[i] == obj)
					cnt++;
			}

			return cnt;
		}
		else if( obj > n[mid] )
			low = mid + 1;
		else if( obj < n[mid] )
			high = mid - 1;
	}

	return 0;
}

int main(void)
{
	cin >> N;
	n.resize(N);

	for(long i=0;i<N;i++)
	{
		cin >> n[i];
	}

	sort(n.begin(),n.end()); // 오름차순 정렬.

	cin >> M;
	m.resize(M);

	for(long i=0;i<M;i++)
	{
		cin >> m[i];
	}

	for(long i=0;i<M;i++)
	{
		printf("%d ",BinarySearch(m[i]));
	}

	return 0;

}