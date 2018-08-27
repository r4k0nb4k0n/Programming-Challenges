#include <cstdio>
#include <algorithm>
using namespace std;
char s[101];
int main()
{
	scanf("%s", s);
	for (char i = 'a'; i <= 'z'; i=i+1)
		printf("%d ", count(s, s + 101, i));
	return 0;
}
