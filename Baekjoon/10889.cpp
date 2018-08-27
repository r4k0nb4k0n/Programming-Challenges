#include <stdio.h>
int cnt[10001];
int main()
{
	long N;  
	scanf("%ld",&N);
	long i;
	for(i=0;i<N;i++)
	{
		int temp;
		scanf("%d",&temp);
		cnt[temp]++;
	}
	int j;
	for(j=1;j<=10000;j++)
	{
		if(cnt[j] != 0)
		{
			int k;
			for(k=1;k<=cnt[j];k++)
				printf("%d\n",j);
		}
	}

	return 0;
}