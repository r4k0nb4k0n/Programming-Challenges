#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	long long i;
	long long j;
	int is_prime = 1;
	scanf("%lld",&n);

	i = 2; // Initializaton
	while(i<=n) // Loop Condition
	{
		 is_prime = 1;
		 j = 2; // Initialization
		 while(j<=(long long)sqrt(i)) // Loop Condition
		 {
			if(n%j==0)
			{
				is_prime = 0;
				break;
			}
			else
				is_prime = 1;
			j++; // Increasing
		}

		if(is_prime == 1)
			printf("%d ",i);

		i++; // Increasing
	}

	return 0;
}
