#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, i, j;
	int table[101];
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= 100; i++)
		table[i] = i;
	while (M--)
	{
		scanf("%d %d", &i, &j);
		reverse(table + i, table + j + 1);
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", table[i]);
	return 0;
}
