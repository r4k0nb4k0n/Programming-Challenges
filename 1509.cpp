#include <cstdio>
#include <string.h>
#include <algorithm>
#include <string>

using namespaces std;

string s;
char temp[2501];
int memo[2501];

bool palindrome(string input)
{
	int START = 0;
	int END = input.length - 1;

	while(S != E && !(S < E))
	{
		if(input[S] != input[E])
			return false;
	}
	return true;
}

int solve(int index)
{
	// 기저조건.
	if(index == s.length - 1)
		return 0;

	int &ret = memo[index];

	for(int i=0;i<index;i++)
	{
		for(int j=1;j<=s.length;j++)
		{
			if( palindrome(s) )
				ret = 1 + min(ret, solve());
		}
	}
}

int main(void)
{
	scanf("%s",s);
	printf("%d",solve(1))
}