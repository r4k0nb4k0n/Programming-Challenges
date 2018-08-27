#include <cstdio>
#include <algorithm>
using namespace std;
int table[101];
int N, M, i, j;
int main()
{
	scanf("%d %d", &N, &M);
	for (i = 0; i < 101; i++)
		table[i] = i;
	while (M--)
	{
		scanf("%d %d", &i, &j);
		swap(table[i], table[j]);
	}
	for (i = 1; i <= N; i++)
		printf("%d ", table[i]);
	return 0;
}
