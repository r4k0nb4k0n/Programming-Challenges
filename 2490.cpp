#include <cstdio>

using namespace std;

int main()
{
	int stomach; // 배. 0.
	int back; // 등. 1.
	for(int i=1;i<=3;i++)
	{
		// 초기화.
		stomach = 0;
		back = 0;
		for(int j=1;j<=4;j++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp)
				back++;
			else
				stomach++;
		}
		if(stomach == 1 && back == 3)
			printf("A\n");
		else if(stomach == 2 && back == 2)
			printf("B\n");
		else if(stomach == 3 && back == 1)
			printf("C\n");
		else if(stomach == 4 && back == 0)
			printf("D\n");
		else if(stomach == 0 && back == 4)
			printf("E\n");
	}

	return 0;
}