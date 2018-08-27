#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d",&N);

	int i;
	int j;
	int k;

	for(i=1;i<=N;i++)
	{
		for(j=N-i;j>0;j--)
			printf(" ");

		for(k=(i*2)-1;k>=1;k--)
		{
			if( k == (i*2)-1 || k == 1 || i == N )
				printf("*");
			else
				printf(" ");

		}
		printf("\n");
	}

	return 0;
}