#include <stdio.h>
#include <math.h>
int main()
{
	char result[100];
	int N, B, i=0;
	scanf("%d %d",&N,&B);
	while(N!=0)
	{
		result[i] = N%B;
		N/=B;
		if (result[i]>=10)
			result[i]+='A'-10;
		else
			result[i]+='0';
		i++;
	}
	while(i--)
		printf("%c",result[i]);
	return 0;
}
