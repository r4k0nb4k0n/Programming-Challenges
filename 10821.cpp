#include <cstdio>
using namespace std;
char s[101];
int idx = 0;
int cnt = 0;

int main()
{
	scanf("%s", s);
	while (s[idx] != '\0')
	{
		if (s[idx] == ',')
			cnt++;
		idx++;
	}
	printf("%d", cnt + 1);
	return 0;
}
