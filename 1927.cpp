#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long> min_heap;
int N;
long long input;
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		scanf("%lld", &input);
		if (input == 0)
		{
			if (min_heap.empty())
				printf("0\n");
			else
			{
				printf("%lld\n", -min_heap.top());
				min_heap.pop();
			}
		}
		else
			min_heap.push(-input);
	}
	return 0;
}
