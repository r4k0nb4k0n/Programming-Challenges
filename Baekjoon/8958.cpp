#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T; // 테스트 케이스의 개수.
	scanf("%d",&T);
	while(T--)
	{
		string input;
		
		while(cin >> input)
		{
			int idx=0;
			int score=0;
			int total=0;
			while(input[idx] != '\0')
			{
				if(input[idx] == 'O')
				{
					score++;
					total += score;
					idx++;
				}
				else
				{
					score = 0;
					idx++;
				}
				
			}
			printf("%d\n",total);
		}
	}
	return 0;
}
