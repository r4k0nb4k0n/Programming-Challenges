#include <stdio.h>

int main(void)
{
	int N;

	scanf("%d",&N);

	int i;
	int j;

	for(int i=1;i<=N;i++)
	{
		if( N % 2 == 1 )
		{
			for(j = (N/2) + 1;j>=1;j--)
				printf("* ");
			printf("\n");
			for(j = N/2;j>=1;j--)
				printf(" *");
		}
		else
		{
			for(j = N/2;j>=1;j--)
				printf("* ");
			printf("\n");
			for(j = N/2;j>=1;j--)
				printf(" *");
		}
		printf("\n");
	}

	return 0;
}