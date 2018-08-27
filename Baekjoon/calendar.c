#include <stdio.h>

int main()
{
	int year, day, date, i, DAYS_OF_MONTH, START_DAY;
	// 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31.
	printf("원하는 연도를 입력하세요 => ");
	scanf("%d",&year);
	for(i=1;i<=12;i++)
	{
		if(i==2)
		{
           	if((year%4)&&!(year%100)||(year%400)) // 윤년
           		DAYS_OF_MONTH=29;
         	else
				DAYS_OF_MONTH=28;
		}
        	else if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            	DAYS_OF_MONTH=31;
        	else
            	DAYS_OF_MONTH=30;

        	if(i==1||i==2)
        	{
            	year--;
            	i+=12;
        	}
		
        	START_DAY=((int)(21*(year/100)/4)+(int)(5*(year%100)/4)+(int)(26*(i+1)/10)+1-1)%7; // 제라의 공식

        	if(i==13||i==14)
        	{
        	    year++;
        	    i-=12;
        	}

		printf("\n++++++++++++<%2d 월>++++++++++++\n",i);
		printf("===============================\n");
		printf("  일   월   화  수   목  금  토\n");
		printf("===============================\n");

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
		printf("\n===============================\n");

	}
	return 0;
}
