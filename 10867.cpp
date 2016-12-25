#include <cstdio>
using namespace std;
bool number[2001];
int main()
{
	int N, temp;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &temp);
		number[temp + 1000] = true;
	}
	for (int i = 0; i < 2001; i++)
	{
		if (number[i])
			printf("%d ", i - 1000);
	}
	return 0;
}
