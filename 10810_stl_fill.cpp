#include <cstdio>
#include <algorithm>
using namespace std;
int basket[101];
int main()
{
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	while (M--)
	{
		scanf("%d %d %d", &i, &j, &k);
		fill(basket + i, basket + j + 1, k);
	}
	for (i = 1; i <= N; i++)
		printf("%d ", basket[i]);
	return 0;
}
