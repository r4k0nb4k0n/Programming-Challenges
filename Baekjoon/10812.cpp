#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> table;
int N, M, i, j, k;
int main()
{
	scanf("%d %d", &N, &M);
	for (i = 0; i < 101; i++)
		table.push_back(i);
	while (M--)
	{
		scanf("%d %d %d", &i, &j, &k);
		rotate(table.begin() + i, table.begin() + k, table.begin() + j + 1);
	}
	for (i = 1; i <= N; i++)
		printf("%d ", table[i]);
	return 0;
}
