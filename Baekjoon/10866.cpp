#include <cstdio>
#include <cstring>
#include <deque>
#define SIZE 20
using namespace std;
int main()
{
	deque<int> Deque; // 정수를 저장하는 덱.
	char cmd[SIZE];
	int X, cnt;

	scanf("%d", &cnt);
	while (cnt--)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "push_front") == 0)
		{
			scanf("%d", &X);
			Deque.push_front(X);
		}
		else if (strcmp(cmd, "push_back") == 0)
		{
			scanf("%d", &X);
			Deque.push_back(X);
		}
		else if (strcmp(cmd, "pop_front") == 0)
		{
			if (!Deque.empty())
			{
				printf("%d\n", Deque.front());
				Deque.pop_front();
			}
			else
				printf("-1\n");
		}
		else if (strcmp(cmd, "pop_back") == 0)
		{
			if (!Deque.empty())
			{
				printf("%d\n", Deque.back());
				Deque.pop_back();
			}
			else
				printf("-1\n");
		}
		else if (strcmp(cmd, "size") == 0)
			printf("%d\n", Deque.size());
		else if (strcmp(cmd, "empty") == 0)
		{
			if (Deque.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(cmd, "front") == 0)
		{
			if (!Deque.empty())
				printf("%d\n", Deque.front());
			else
				printf("-1\n");
		}
		else if (strcmp(cmd, "back") == 0)
		{
			if (!Deque.empty())
				printf("%d\n", Deque.back());
			else
				printf("-1\n");
		}
		fflush(stdin);
	}
	return 0;
}
