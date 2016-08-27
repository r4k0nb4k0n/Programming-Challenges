#include <stdio.h>
#define FFLUSH  while(getchar() != '\n')

int main()
{
	int N;
	char num[101];
	int sum = 0;
	int i;

	scanf("%d",&N);
	FFLUSH;
	fgets(num,sizeof(num),stdin);

	for(i=0;i<N;i++)
		sum = sum + (num[i] - 48);
	
	printf("%d",sum);
}