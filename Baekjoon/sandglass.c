#include <stdio.h>
int main()
{
	int n, i, j;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<i)
				printf(" ");
			else
				printf("%d",j);
		}
		for(j=n-1;j>=1;j--)
		{
			if(j<i)
				printf(" ");
			else
				printf("%d",j);
		}
		printf("\n");
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(j<i)
				printf(" ");
			else
				printf("%d",j);
		}
		for(j=n-1;j>=1;j--)
		{
			if(j<i)
				printf(" ");
			else
				printf("%d",j);
		}
		printf("\n");
	}
	
	return 0;
}
