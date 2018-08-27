#include <cstdio> // printf(),scanf().
#include <string.h> // memset().
#define SIZE 1000001

using namespace std;

bool prime[SIZE]; // 원하는 수만큼의 크기로 소수판별 논리변수 선언.

void eratos() // 에라토스테네스의 체. Eratosthenes' sieve.
{
	// 소수가 아닌 것을 지워나가는 식의 알고리즘이기 때문에
	memset(prime,true,sizeof(prime)); // 전체를 true로 초기화.
	// 0, 1은 소수가 아니다.
	prime[0] = false;
	prime[1] = false;

	for(int i=2;i*i<=SIZE;i++) // 2부터 시작;i^2가 원하는 수만큼보다 작을때
	{
		for(int j=i+i;j<=SIZE;j+=i) // i의 2배수부터 시작;;i씩 더해짐.
			prime[j] = false; // 해당되는 수 지워감.
	}
}

int main()
{
	eratos();
	int M,N;
	scanf("%d %d",&M,&N);
	for(int i=M;i<=N;i++)
	{
		if(prime[i])
			printf("%d\n",i);
	}
	return 0;
}