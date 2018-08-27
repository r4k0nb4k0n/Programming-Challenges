#include <cstdio>
#include <cstring>

int main()
{
	char s[101];
	gets(s);
	for (int i = 0; i < strlen(s); i++)
	{
		if ('A' <= s[i] && s[i] <= 'z')
		{
			if ('A' <= s[i] && s[i] <= 'Z')
				s[i] = (((s[i] - 'A') + 13) % ('Z' - 'A'+1)) + 'A';
			else if ('a' <= s[i] && s[i] <= 'z')
				s[i] = (((s[i] - 'a') + 13) % ('z' - 'a'+1)) + 'a';
		}
	}
	puts(s);
	return 0;
}
