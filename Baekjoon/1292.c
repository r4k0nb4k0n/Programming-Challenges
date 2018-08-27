#include <stdio.h>

int main(void)
{
	int seq[1000];

	int i;
	int j;
	int k=0;

	for(i=1;i<=45;i++)
	{
		if(i == 45)
		{
			for(j=1;j<=10;j++)
			{
				seq[k] = i;
				k++;
			}
		}
		else
		{
			for(j=1;j<=i;j++)
			{
				seq[k] = i;
				k++;
			}

		}
	}

	int A, B;

	scanf("%d %d",&A,&B);

	int sum=0;

	for(i=A-1;i<=B-1;i++)
		sum = sum + seq[i];

	printf("%d\n",sum);
}