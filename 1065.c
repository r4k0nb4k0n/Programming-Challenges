#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int cnt = 0;
	int first = 0;
	int second = 0;
	int third = 0;

	for(int i=N;i>=1;i--)
	{
		if( i>=1 && i<=99 )
			cnt++;
		else
		{
			third = i/100;
			second = (i-third*100)/10;
			first = i - third*100 - second*10;

			if( (first - second) == (second - third) )
				cnt++;
		}
	}
	printf("%d",cnt);
}