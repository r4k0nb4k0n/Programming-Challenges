#include <stdio.h> // 표준입출력
#include <iostream> //
#include <vector> // 리스트
#include <algorithm> // sort함수.

using namespace std;

vector<int> v; // int형 리스트 v 선언.
int N; // 데이터 수 N 선언.

bool BinarySearch(int obj) // 이분탐색 BinarySearch 선언.
{
	int low, mid, high;

	low = 0;
	high = N-1;

	while(1)
	{
		mid = (low + high) / 2;
		if( obj == v[mid] )
			break;
		else if( obj > v[mid] )
			low = mid + 1;
		else if ( obj < v[mid] )
			high = mid - 1;
	}

	if( obj == v[mid] )
		return true;
	else
		return false;
}

int main(void)
{
    scanf("%d",&N); // 데이터 수 N 입력받음.
    int x;
    scanf("%d",&x); // 탐색할 데이터 입력받음.
    
    v.resize(N); // 리스트 크기 N으로 조정.

    for(int i=0;i<N;i++)
    {
    	scanf("%d",&v[i]);
    }

    sort(v.begin(),v.end()); // 퀵소트 오름차순 정렬.

    if( BinarySearch(x) == true )
    	printf("True");
    else
    	printf("False");

    return 0;

}