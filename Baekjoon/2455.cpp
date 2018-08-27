#include <cstdio>

using namespace std;

int main()
{
	int train_MAX = 0; // 기차에 사람이 가장 많을 때의 사람 수.
	int train_NOW = 0;
	int out, in;

	for(int i=1;i<=4;i++)
	{
		scanf("%d %d",&out,&in);
		train_NOW = train_NOW - out + in;
		if(train_NOW > train_MAX)
			train_MAX = train_NOW;
	}

	printf("%d",train_MAX);
	return 0;
}