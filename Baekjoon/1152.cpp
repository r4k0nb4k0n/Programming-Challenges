#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char s[1000001]; // maximum length : 1,000,000
	gets(s); // including space
	int cnt = 0; // the number of vocabularies
	int idx = 0; // index
	bool now_voca = false;
	if (s[idx] != ' ')
		now_voca = true;
	while (s[idx] != '\0')
	{
		if (s[idx] == ' ') // space
		{
			if (now_voca == true)
			{
				cnt++;
				now_voca = false;
			}
			idx++;
		}
		else // not space
		{
			now_voca = true;
			idx++;
		}
	}
	if (s[idx - 1] != ' ') // last is not space
		printf("%d", cnt + 1);
	else // last is space
		printf("%d", cnt);
	return 0;
}
