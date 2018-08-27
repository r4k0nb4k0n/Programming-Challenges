#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N;i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
		printf("%d\n", v[i]);
	return 0;
}
