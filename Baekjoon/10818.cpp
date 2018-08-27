#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
	int N, temp;
	int MIN = INT_MAX;
	int MAX = INT_MIN;

	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &temp);
		MIN = min(temp, MIN);
		MAX = max(temp, MAX);
	}
	printf("%d %d", MIN, MAX);
	return 0;
}
