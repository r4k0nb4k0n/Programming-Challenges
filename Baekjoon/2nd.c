#include <stdio.h>

int main(void)
{
	int input;
	int temp = 0;
	int data[3];
	int result[2];
	int mark = 0;
	int cnt = 0;
	int i;

	for(i=0;i<3;i++)
	{
		scanf("%d",&data[i]);
		if(temp<=data[i])
		{
			temp = data[i];
			mark = i;
		}
	}

	for(i=0;i<3;i++)
	{
		if(i != mark)
		{
			result[cnt] = data[i];
			cnt++;
		}
	}

	if(result[0]>=result[1])
		printf("%d",result[0]);
	else
		printf("%d",result[1]);
}