#include <stdio.h>
#define START_DAY 3
#define DAYS_OF_MONTH 31

int main()
{
	int year, day, date, i;
	scanf("%d",&year);
	for(i=1;i<=12;i++)
	{
		printf("%d 월\n",i);
		printf("=================================\n");
		printf("  일  월  화  수  목  금  토\n");
		printf("=================================\n");

		for(day = 0;day<START_DAY;day++)
			printf("    "); // 커서 옮김.
		for(date=1;date<=DAYS_OF_MONTH;date++)
		{
			if(day==7)
			{
				day=0;
				printf("\n");
			}
			day++;
			printf("%4d", date);
		}
		printf("\n=================================\n");
	}
	return 0;
}	
