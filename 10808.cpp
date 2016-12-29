#include <cstdio>
char s[101];
int cnt['z' - 'a' + 1];
int main()
{
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++)
		cnt[s[i] -'a']++;
	for (int i = 0; i <= 'z' - 'a'; i++)
		printf("%d ", cnt[i]);
	return 0;
}
