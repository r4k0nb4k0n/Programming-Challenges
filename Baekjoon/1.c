#include <stdio.h>

// 1은 소수가 아니라고 수학에서 정의하고 있습니다. 그래서 1에서 n 사이의 소수를 출력할 때 1을 제외했습니다.

int main()
{
	int n;
	int i;
	int j;
	int is_prime;
	printf("n을 입력하시오 : ");
	scanf("%d",&n);
	
	printf("1에서 %d 사이의 소수는\n",n);
	
	if(n == 2)
	{
		printf("2 입니다.");
		return 0;
	}
	else if(n == 3)
	{
		printf("2, 3 입니다.");
		return 0;
	}
	else if(n <= 1)
	{
		printf("있을 수 없습니다. 1보다 큰 수를 입력해주세요.");
		return 0;
	}
	else
	{
		i = 2; // 초기식.
		while(i<=n) // 반복 조건.
		{
			is_prime = 1;
			j = 2; // 초기식.
			while(j*j<=i) // 반복 조건. sqrt 함수 호출할 필요없음.
			{
				if(i%j==0) // 나누어 떨어진다면, 소수가 아님.
				{
					is_prime = 0;
					break;
				}
				j++; // 증감식.
				if(is_prime == 0)
					break;
			}
			if(is_prime == 1)
			{
				printf("%d",i);
				if(i!=n)
					printf(", ");	
			}
				
			i++; // 증감식.
		}
		
	}
	if(is_prime == 0)
		printf("\b\b");
	
	printf(" 입니다.\n");
	return 0;
}
