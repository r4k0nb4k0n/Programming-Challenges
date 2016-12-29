#include <cstdio>
int N, v;
int number[201];
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		int temp;
		scanf("%d", &temp);
		number[temp + 100]++;
	}
	scanf("%d", &v);
	printf("%d", number[v + 100]);
	return 0;
}
