#include <cstdio>
#include <algorithm>
using namespace std;
char s[101];
int main()
{
	scanf("%s", s);
	for (char i = 'a'; i <= 'z'; i = i + 1)
	{
		char* p = find(s, s + 101, i);
		if (p == s + 101)
			printf("-1 ");
		else
			printf("%d ", p - s);
	}
	return 0;
}
