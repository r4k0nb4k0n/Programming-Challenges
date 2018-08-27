#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, i, temp;
	vector<int> arr;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &temp);
		printf("%d ", binary_search(arr.begin(), arr.end(), temp));
	}
	return 0;
}
