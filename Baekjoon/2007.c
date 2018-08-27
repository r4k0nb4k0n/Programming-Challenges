#include <stdio.h>
int main(void)
{
	int x,y;
	int m;
	int day=0;
	scanf("%d %d",&x,&y);

	for(m=1;m<x;m++)
	{
		if(m == 2)
			day = day + 28;
		else if(m == 4 || m == 6 || m == 9 || m == 11)
			day = day + 30;
		else
			day = day + 31;
	}

	day = day + (y-1);

	switch(day%7)
	{
		case 0:
			printf("MON");
			break;
		case 1:
			printf("TUE");
			break;
		case 2:
			printf("WED");
			break;
		case 3:
			printf("THU");
			break;
		case 4:
			printf("FRI");
			break;
		case 5:
			printf("SAT");
			break;
		case 6:
			printf("SUN");
			break;
	}
}