#include <cstdio>

using namespace std;

int main(void)
{
	int N;

	scanf("%d",&N);
	int temp = N;
	for(int i=2;i<=(temp/2)+2;i++)
	{
		while(N%i == 0)
		{
			N = N / i;
			printf("%d\n",i);
			if(N == 1)
				break;
			
		}
		if( N == 1 )
			break;
	}
	return 0;
}