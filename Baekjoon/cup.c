#include <stdio.h>

int main()
{
	char order[50];
	char temp_ch;
	int temp_int;
	int cup[3]={1,0,0};
	int i=0;

	fgets(order,sizeof(order),stdin);

	while(order[i]!='\0')
	{
		temp_ch=order[i];
		switch(temp_ch)
		{
			case 'A':
				temp_int=cup[0];
				cup[0]=cup[1];
				cup[1]=temp_int;
				break;
			case 'B':
				temp_int=cup[1];
				cup[1]=cup[2];
				cup[2]=temp_int;
				break;
			case 'C':
				temp_int=cup[2];
				cup[2]=cup[0];
				cup[0]=temp_int;
				break;
			default:
				break;
		}
		i++;
	}
	i=0;
	while(cup[i]==0)
		i++;
	printf("%d",i+1);
}