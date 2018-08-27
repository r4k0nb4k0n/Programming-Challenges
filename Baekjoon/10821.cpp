#include <cstdio>
int main()
{
	char c;
	int cnt = 0;
	while ((c = getchar()) && c != '\n')
		if (c == ',')
			cnt++;
	printf("%d", cnt + 1);
	return 0;
}
