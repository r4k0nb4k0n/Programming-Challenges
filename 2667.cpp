#include <cstdio>

using namespace std;

int N; // 지도의 크기.
int map[25][25];
bool visited[25][25];
int cnt; // 단지수.
int temp;
int houses[625]; // 각 단지내 집의 수.

int x_move[4] = {1, -1, 0, 0};
int y_move[4] = {0, 0, 1, -1};

void DFS(int x, int y)
{
	visited[x][y] = true;
	houses[cnt]++;

	for(int i=0;i<4;i++)
	{
		int x_next = x + x_move[i];
		int y_next = y + y_move[i];

		if( 0 <= x_next && x_next < N && 0 <= y_next && y_next < N )
			DFS(x_next,y_next);
	}
}

int main(void)
{
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			scanf("%1d",&map[i][j]);
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!visited[i][j])
			{
				cnt++;
				DFS(i,j);
			}
		}
	}

	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d\n",houses[i]);

	return 0;
}