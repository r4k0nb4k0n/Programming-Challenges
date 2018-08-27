#include <stdio.h>

void main()
{
	int i;
	int sum = 0;
	int input;

	scanf("%d", &input);

	for(i=1;i<=input;i++)
		sum = sum + i;

	printf("%d\n",sum);
}