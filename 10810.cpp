#include <cstdio>
int N, M;
int i, j, k;
int basket[101];

int main()
{
	scanf("%d %d", &N, &M);
	while (M--)
	{
		scanf("%d %d %d", &i, &j, &k);
		for (; i <= j; i++)
			basket[i] = k;
	}
	for (i = 1; i <= N; i++)
		printf("%d ", basket[i]);
	return 0;
}
