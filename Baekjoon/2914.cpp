#include <cstdio>

using namespace std;

int main()
{
	int A; // 앨범에 수록된 곡의 개수.
	int I; // 평균값. 무조건 올림해준 값.

	scanf("%d %d",&A,&I);
	printf("%d",A*(I-1)+1);
	return 0;
}