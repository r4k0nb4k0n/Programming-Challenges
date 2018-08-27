#include <stdio.h>
#define FFLUSH  while(getchar() != '\n')
int main(void)
{
	int N;
	int i;
	int j;
	int k;
	int cursor;
	int front;

	char input[1000001];
	char output[1000001];
	char queue[1000001];
	
	FFLUSH;

	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		FFLUSH;
		j = 0;
		front = 0;
		cursor = 0;
		scanf("%s",input);
		while(input[j] != '\0')
		{
			if(input[j] == '<')
			{
				if(cursor != 0)
				{
					queue[front] = output[cursor];
					cursor--;
					front = front + 1;
				}
			}
			else if(input[j] == '>')
			{
				if(cursor != 1000000)
					cursor++;
			}
			else if(input[j] == '-')
			{
				output[cursor] = '\0';
				cursor--;
			}
			else
			{
				if(front != 0)
				{
					for(k=0;k<=front;k++)
					{
						output[cursor] = queue[k];
						cursor++;
					}
					output[cursor] = input[j];
					cursor++;
				}
				else
				{
					output[cursor] = input[j];
					cursor++;
				}
			}
			j++;
		}
		printf("\n");
	}
}