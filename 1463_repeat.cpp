#include <cstdio> // scanf, printf.
#include <cstring> // memset.
#include <algorithm> // min.

using namespace std;

int memo[1000001]; // 메모이제이션 변수. N<=1,000,000이어서 크기가 1000001.

int solve(int N)
// 함수의 정의 : 정수 N을 1로 만들 때 연산을 사용하는 횟수의 최소값 리턴.
{
	// 기저조건.
	if( N == 3 || N == 2 )
		return 1;

	int &ret = memo[N];

	if( ret != -1 )
		return ret;

	ret = solve(N-1)+1; // 3. 1을 뺀다.

	if( N % 3 == 0 ) // 1. X가 3으로 나누어 떨어지면,
		ret = min(solve(N/3)+1, ret); // 3으로 나눈다.
	if( N % 2 == 0 ) // 2. X가 2로 나누어 떨어지면,
		ret = min(solve(N/2)+1, ret); // 2로 나눈다.
	
	return ret;
}

int main(void)
{
	int X;
	memset(memo,-1,sizeof(memo)); // memo를 -1로 초기화.
	scanf("%d",&X);
	printf("%d",solve(X));
	return 0;
}
