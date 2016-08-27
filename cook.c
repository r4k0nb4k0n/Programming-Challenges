#include <stdio.h>

int main(void)
{
	int i,j;
	int temp;
	int score[5]={0,0,0,0,0};
	int winnum=0;
	int winscr=0;

	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&temp);
			score[i]=score[i]+temp;
		}
		if(score[i]>winscr)
		{
			winscr = score[i];
			winnum = i+1;
		}
	}

	printf("%d %d",winnum,winscr);
}