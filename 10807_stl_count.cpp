#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, v, nums[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	scanf("%d", &v);
	printf("%d", count(nums, nums + N, v));
	return 0;
}
