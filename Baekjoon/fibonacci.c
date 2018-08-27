#include <stdio.h>

int zero = 0;
int one = 0;

int fibonacci(int n)
{
	if(n==0)
	{
		zero++;
		return 0;
	}
	else if(n==1)
	{
		one++;
		return 1;
	}
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
	int T;
	int i;
	int temp[100];

	scanf("%d",&T);

	for(i=0;i<T;i++)
		scanf("%d",&temp[i]);

	for(i=0;i<T;i++)
	{
		fibonacci(temp[i]);
		printf("%d %d\n",zero,one);
		zero = 0;
		one = 0;
	}
}