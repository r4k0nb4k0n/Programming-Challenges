#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char s[1000001];
	gets(s);
	int cnt = 0;
	int idx = 0;
	bool now_voca = false;
	if(s[idx] != ' ')
		now_voca = true;
	while(s[idx] != '\0')
	{
		if(s[idx] == ' ')
		{
			if(now_voca == true)
			{
				cnt++;
				now_voca = false;
			}
			idx++;
		}
		else
		{
			now_voca = true;
			idx++;
		}
	}
	if(s[idx-1] != ' ')
		printf("%d",cnt+1);
	else
		printf("%d",cnt);
	return 0;
}
