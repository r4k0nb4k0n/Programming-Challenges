#include <cstdio>
#include <vector>
using namespace std;
pair<int, int> balloon[1001]; 
//.first : the number in the balloon
//.second : the order of the balloon
bool ispopped[1001];
int N, pivot;

void input()
{
	scanf("%d", &N);
	int temp;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &temp);
		balloon[i] = make_pair(temp, i);
	}
}

void solve()
{
	bool isnegative;
	int value_abs;
	pivot = 1; ispopped[1] = true; printf("1 ");
	for (int i = 2; i <= N; i++) // Loop N-1 times.
	// i begins from 2, because the first balloon is already popped.
	{
		if (balloon[pivot].first < 0) // left
		{
			isnegative = true;
			value_abs = -balloon[pivot].first;
		}
		else // right
		{
			isnegative = false;
			value_abs = balloon[pivot].first;
		}

		for (int j = 1; j <= value_abs;)
		{
			if (isnegative) // left
				pivot--;
			else // right
				pivot++;

			// when pivot is out of range
			if (pivot < 1)
				pivot = pivot + N;
			else if (pivot > N)
				pivot = pivot - N;

			if (!ispopped[pivot]) // count without balloons which are already popped.
				j++;
		}

		ispopped[pivot] = true;
		printf("%d ", balloon[pivot].second);

	}
}

int main()
{
	input();
	solve();
	return 0;
}
