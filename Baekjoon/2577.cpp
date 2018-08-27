#include <cstdio>

using namespace std;
int cnt[10];
int main()
{
	int A, B, C;
	scanf("%d %d %d",&A,&B,&C);
	long long int multiply = A*B*C;
	while(multiply>10)
	{
		cnt[multiply%10]++;
		multiply /= 10;
	}
	cnt[multiply]++;
	for(int i=0;i<10;i++)
		printf("%d\n",cnt[i]);
	return 0;
}
