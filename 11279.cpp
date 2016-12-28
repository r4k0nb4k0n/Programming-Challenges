#include <cstdio>
#include <queue>

using namespace std;

priority_queue<long long> max_heap;
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
			if (max_heap.empty())
				printf("0\n");
			else
			{
				printf("%lld\n", max_heap.top());
				max_heap.pop();
			}
		}
		else
			max_heap.push(input);
	}
	return 0;
}
