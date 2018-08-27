#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
	int num;
	int is_Prime[99999];
	int i;
	int j;

	scanf("%d",&num);

	// Fill All numbers in is_Prime[].
	i=1; // Initialization.
	while(i<=num) // Loop condition.
	{
		is_Prime[i] = i;
		i++; // Increasing.
	}

	// Eratosthenes' sieves ( 1 ~ sqrt(n) )
	i=2; // Initialization.
	while(i<=sqrt(num)) // Loop condition.
	{
		j=i+i; // Initialization.
		while(j<=num) // Loop condition
		{
			is_Prime[j] = 0;
			j+=i; // Increasing.
		}

		i++; // Increasing.
	}

	// Print Answers.
	i=2; // Initialization.
	while(i<=num) // Loop condition.
	{
		if(is_Prime[i] != 0)
			printf("%d ",is_Prime[i]);
		i++; // Increasing.
	}

	return 0;
}
