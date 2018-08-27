#include <cstdio>

using namespace std;

int main()
{
	int burger = 0;
	int beverage = 0;
	int temp;

	scanf("%d",&temp);
	for(int i=2;i<=3;i++)
	{
		scanf("%d",&temp);
		if(burger>temp)
			burger = temp;
	}
	scanf("%d",&temp);
	beverage = temp;
	scanf("%d",&temp);
	if(beverage>temp)
		beverage = temp;
	printf("%d",burger+beverage-50);
	return 0;
}