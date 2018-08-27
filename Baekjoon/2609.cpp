#include <cstdio> // printf(),scanf().

using namespace std;

int gcd(int a, int b) // 두 수의 최대공약수를 리턴하는 함수.
{
	if(b == 0) // 기저조건.
		return a;
	return gcd(b, a%b); // 재귀함수.
}

int main(void)
{
	int M,N; // 10,000 이하의 자연수.
	int GCD,LCM;

	scanf("%d %d",&M,&N);

	GCD = gcd(M,N); // 최대공약수.
	LCM = M*N/GCD; // 최소공배수.

	printf("%d\n%d",GCD,LCM);
	return 0;
}